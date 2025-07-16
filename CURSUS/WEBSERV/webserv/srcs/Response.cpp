#include "Response.hpp"
#include "CGI.hpp"
#include <sys/stat.h>  // For file statistics
#include <dirent.h>    // For directory operations
#include <unistd.h>    // For file access functions
#include <fcntl.h>     // For file control operations
#include <cerrno>      // For error number definitions
#include <fstream>     // For file stream operations
#include <iostream>    // For input/output stream operations
#include <sstream>     // For string stream operations
#include <ctime>       // For time operations
#include <cstdlib>     // For standard library functions
#include <map>         // For map container
#include <string>      // For string operations
#include <cstring>     // For C string functions
#include <iomanip>     // For I/O manipulation

class SessionManager {  // Session management class for bonus feature
private:
    std::map<std::string, int> visit_counts;  // Map to store visit counts per session
    static int counter;  // Static counter for unique session IDs
public:
    SessionManager() {}  // Default constructor
    std::string createSession() {  // Create new session with unique ID
        std::ostringstream oss;
        oss << ::time(NULL) << "_" << counter++;  // Combine timestamp and counter
        std::string session_id = oss.str();
        visit_counts[session_id] = 1;  // Initialize visit count
        std::cerr << "DEBUG: Created session: " << session_id << ", visit_count: 1" << std::endl << std::flush;
        return session_id;
    }
    int incrementVisit(const std::string& session_id) {  // Increment visit count for existing session
        if (visit_counts.find(session_id) != visit_counts.end()) {
            visit_counts[session_id]++;  // Increment count
            std::cerr << "DEBUG: Incremented visit for session: " << session_id << ", new count: " << visit_counts[session_id] << std::endl << std::flush;
            return visit_counts[session_id];
        }
        std::cerr << "DEBUG: Session not found: " << session_id << std::endl << std::flush;
        return 0;
    }
    int getVisitCount(const std::string& session_id) {  // Get visit count for session
        if (visit_counts.find(session_id) != visit_counts.end()) {
            return visit_counts[session_id];
        }
        return 0;
    }
};
int SessionManager::counter = 0;  // Initialize static counter

Response::Response(const Request& req, const ServerConfig& config, int port)  // Constructor implementation
    : request(req), config(config), port(port), status_code(200) {  // Initialize member variables
    std::cerr << "DEBUG: Constructing Response for method: " << request.getMethod() << ", URI: " << request.getUri() << std::endl << std::flush;
}

std::string Response::trim(const std::string& str) const {  // Remove leading/trailing whitespace
    size_t start = str.find_first_not_of(" \t\r\n");  // Find first non-whitespace
    size_t end = str.find_last_not_of(" \t\r\n");     // Find last non-whitespace
    if (start == std::string::npos) return "";  // String is all whitespace
    return str.substr(start, end - start + 1);  // Return trimmed string
}

const LocationConfig* Response::findLocation(const std::string& uri) const {  // Find best matching location config
    std::cerr << "DEBUG: findLocation for URI: " << uri << std::endl << std::flush;
    const LocationConfig* best_match = NULL;  // Best matching location
    size_t longest_match = 0;  // Length of longest path match
    for (size_t i = 0; i < config.locations.size(); ++i) {  // Iterate through all locations
        const std::string& loc_path = config.locations[i].path;  // Current location path
        if (uri.find(loc_path) == 0) {  // Check if URI starts with location path
            if (loc_path.length() >= longest_match) {  // Check if this is a better match
                longest_match = loc_path.length();  // Update longest match length
                best_match = &config.locations[i];  // Update best match pointer
                std::cerr << "DEBUG: Matched location: " << loc_path
                          << ", root: " << config.locations[i].root
                          << ", directory_listing: " << (config.locations[i].directory_listing ? "on" : "off")
                          << ", cgi_paths size: " << config.locations[i].cgi_paths.size()
                          << ", index: " << config.locations[i].index
                          << ", redirect: " << config.locations[i].redirect
                          << ", client_max_body_size: " << config.locations[i].client_max_body_size << std::endl << std::flush;
                for (std::map<std::string, std::string>::const_iterator it = config.locations[i].cgi_paths.begin();
                     it != config.locations[i].cgi_paths.end(); ++it) {  // Log CGI paths
                    std::cerr << "DEBUG: cgi_path for extension: " << it->first << " -> " << it->second << std::endl << std::flush;
                }
            }
        }
    }
    if (best_match) {  // If we found a match
        std::cerr << "DEBUG: Selected location: " << best_match->path << std::endl << std::flush;
        return best_match;
    }
    std::cerr << "DEBUG: No specific location matched, using default" << std::endl << std::flush;
    return NULL;  // No location matched
}

bool Response::fileExists(const std::string& path) const {  // Check if file or directory exists
    struct stat buffer;  // Buffer for file statistics
    int result = stat(path.c_str(), &buffer);  // Get file statistics
    std::cerr << "DEBUG: Checking if path exists: " << path << ", stat result: " << result << std::endl << std::flush;
    return (result == 0);  // Return true if stat succeeded
}

bool Response::isDirectory(const std::string& path) const {  // Check if path is a directory
    struct stat buffer;  // Buffer for file statistics
    if (stat(path.c_str(), &buffer) != 0) {  // Get file statistics
        std::cerr << "DEBUG: stat failed for path: " << path << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl << std::flush;
        return false;  // Return false if stat failed
    }
    return S_ISDIR(buffer.st_mode);  // Check if it's a directory
}

std::string Response::getMimeType(const std::string& path) const {  // Determine MIME type from file extension
    std::string extension;  // File extension
    size_t dot_pos = path.find_last_of(".");  // Find last dot in path
    if (dot_pos != std::string::npos && dot_pos < path.length() - 1) {  // If dot found and not at end
        extension = path.substr(dot_pos + 1);  // Extract extension
    }
    if (extension == "html") return "text/html";  // HTML files
    if (extension == "txt") return "text/plain";  // Text files
    if (extension == "jpg" || extension == "jpeg") return "image/jpeg";  // JPEG images
    if (extension == "png") return "image/png";  // PNG images
    if (extension == "php" || extension == "py") return "text/html";  // CGI scripts output HTML
    return "application/octet-stream";  // Default binary type
}

std::string Response::generateDirectoryListing(const std::string& path, const std::string& uri) const {  // Generate HTML directory listing
    std::cerr << "DEBUG: Generating directory listing for: " << path << std::endl << std::flush;
    DIR* dir = opendir(path.c_str());  // Open directory
    if (!dir) {  // If opening failed
        std::cerr << "ERROR: Failed to open directory: " << path << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl << std::flush;
        return "";  // Return empty string
    }
    std::ostringstream listing;  // String stream for HTML content
    listing << "<html><head><title>Directory Listing</title></head><body><h1>Directory Listing for " << uri << "</h1><ul>";  // HTML header
    struct dirent* entry;  // Directory entry
    while ((entry = readdir(dir)) != NULL) {  // Read each directory entry
        std::string name = entry->d_name;  // Entry name
        if (name != "." && name != "..") {  // Skip current and parent directory
            listing << "<li><a href=\"" << uri;  // Create link
            if (uri[uri.length() - 1] != '/') listing << "/";  // Add slash if needed
            listing << name << "\">" << name << "</a></li>";  // Complete link
        }
    }
    listing << "</ul></body></html>";  // HTML footer
    closedir(dir);  // Close directory
    return listing.str();  // Return HTML string
}

std::string Response::readFile(const std::string& path) const {  // Read file content safely
    int fd = open(path.c_str(), O_RDONLY | O_NONBLOCK);  // Open file for reading (non-blocking)
    if (fd < 0) {  // If opening failed
        std::cerr << "ERROR: Failed to open file: " << path << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl << std::flush;
        return "";  // Return empty string
    }
    std::string content;  // File content
    char buffer[4096] = {0};  // Read buffer
    ssize_t bytes_read;  // Number of bytes read
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {  // Read file in chunks
        content.append(buffer, bytes_read);  // Append to content
    }
    close(fd);  // Close file descriptor
    if (bytes_read < 0) {  // If read error occurred
        std::cerr << "ERROR: Failed to read file: " << path << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl << std::flush;
        return "";  // Return empty string
    }
    return content;  // Return file content
}

std::string Response::resolvePath(const LocationConfig* location) const {  // Resolve final file system path
    std::string uri = request.getUri();  // Get request URI
    std::string path;  // Final resolved path
    if (location && !location->upload_path.empty()) {  // If location has upload path
        path = location->upload_path + (uri == location->path ? "" : uri.substr(location->path.length()));  // Use upload path
    } else {  // Normal file serving
        std::string root = location && !location->root.empty() ? location->root : config.root;  // Get root directory
        if (location && uri.find(location->path) == 0) {  // If URI matches location path
            if (uri == location->path || uri[location->path.length()] == '/') {  // Exact match or subdirectory
                path = root + (uri == location->path ? "" : uri.substr(location->path.length()));  // Remove location prefix
            } else {  // Partial match
                path = root + uri;  // Use full URI
            }
        } else {  // No location match
            path = root + uri;  // Use server root + URI
        }
    }
    path = trim(path);  // Remove any whitespace
    std::cerr << "DEBUG: Resolved path: " << path << std::endl << std::flush;
    return path;  // Return resolved path
}

std::string Response::handleUpload(const std::string& upload_path) {  // Handle file upload via POST method
    std::cerr << "DEBUG: Handling upload to: " << upload_path << std::endl << std::flush;

    // Obtener el cuerpo de la solicitud
    std::string body = request.getBody();  // Get request body content
    std::cerr << "DEBUG: Body to be written in handleUpload (string): [" << body << "]" << std::endl << std::flush;
    std::cerr << "DEBUG: Body to be written in handleUpload (hex): ";
    for (size_t i = 0; i < body.size(); ++i) {  // Log body in hexadecimal for debugging
        std::cerr << std::hex << std::setw(2) << std::setfill('0') << (int)(unsigned char)body[i] << " ";
    }
    std::cerr << std::dec << std::endl << std::flush;

    if (body.empty()) {
        std::cerr << "ERROR: Empty request body for upload" << std::endl << std::flush;
        status_code = 400;
        std::string error_page = config.error_pages.find(400) != config.error_pages.end() ? config.root + config.error_pages.find(400)->second : config.root + "/errors/400.html";
        std::string content = readFile(error_page);
        if (content.empty()) content = "<html><body><h1>400 Bad Request - Empty Body</h1></body></html>";
        std::ostringstream response;
        response << "HTTP/1.1 400 Bad Request\r\n"
                << "Content-Type: text/html\r\n"
                << "Content-Length: " << content.length() << "\r\n"
                << "Connection: close\r\n"
                << "\r\n"
                << content;
        return response.str();
    }

    // Verificar el tamaño del cuerpo
    const LocationConfig* location = findLocation(request.getUri());
    size_t max_body_size = location ? location->client_max_body_size : config.client_max_body_size;
    if (body.length() > max_body_size) {
        std::cerr << "DEBUG: Request body size (" << body.length() << ") exceeds client_max_body_size (" << max_body_size << ")" << std::endl << std::flush;
        status_code = 413;
        std::string error_page = config.error_pages.find(413) != config.error_pages.end() ? config.root + config.error_pages.find(413)->second : config.root + "/errors/413.html";
        std::string content = readFile(error_page);
        if (content.empty()) content = "<html><body><h1>413 Payload Too Large</h1></body></html>";
        std::ostringstream response;
        response << "HTTP/1.1 413 Payload Too Large\r\n"
                << "Content-Type: text/html\r\n"
                << "Content-Length: " << content.length() << "\r\n"
                << "Connection: close\r\n"
                << "\r\n"
                << content;
        return response.str();
    }

    // Obtener el nombre del archivo
    std::string filename = request.getHeader("X-Filename");
    if (filename.empty() && request.getUri().find("/Uploads/") == 0 && request.getUri().length() > 9) {
        filename = request.getUri().substr(9);
        std::cerr << "DEBUG: Using filename from URI: " << filename << std::endl << std::flush;
    }
    if (filename.empty()) {
        std::cerr << "ERROR: No filename provided for upload" << std::endl << std::flush;
        status_code = 400;
        std::string error_page = config.error_pages.find(400) != config.error_pages.end() ? config.root + config.error_pages.find(400)->second : config.root + "/errors/400.html";
        std::string content = readFile(error_page);
        if (content.empty()) content = "<html><body><h1>400 Bad Request - No Filename Provided</h1></body></html>";
        std::ostringstream response;
        response << "HTTP/1.1 400 Bad Request\r\n"
                << "Content-Type: text/html\r\n"
                << "Content-Length: " << content.length() << "\r\n"
                << "Connection: close\r\n"
                << "\r\n"
                << content;
        return response.str();
    }

    // Construir la ruta del archivo
    std::string filepath = upload_path + (upload_path[upload_path.length() - 1] == '/' ? "" : "/") + filename;
    std::cerr << "DEBUG: Saving uploaded file to: " << filepath << std::endl << std::flush;

    // Verificar permisos de escritura en el directorio
    std::string dir_path = upload_path;
    if (access(dir_path.c_str(), W_OK) != 0) {
        std::cerr << "ERROR: No write permission for upload directory: " << dir_path 
                  << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl << std::flush;
        status_code = 500;
        std::string error_page = config.error_pages.find(500) != config.error_pages.end() ? config.root + config.error_pages.find(500)->second : config.root + "/errors/500.html";
        std::string content = readFile(error_page);
        if (content.empty()) content = "<html><body><h1>500 Internal Server Error - No Write Permission</h1></body></html>";
        std::ostringstream response;
        response << "HTTP/1.1 500 Internal Server Error\r\n"
                << "Content-Type: text/html\r\n"
                << "Content-Length: " << content.length() << "\r\n"
                << "Connection: close\r\n"
                << "\r\n"
                << content;
        return response.str();
    }

    // Abrir el archivo para escritura
    int fd = open(filepath.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        std::cerr << "ERROR: Failed to open file for writing: " << filepath 
                  << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl << std::flush;
        status_code = 500;
        std::string error_page = config.error_pages.find(500) != config.error_pages.end() ? config.root + config.error_pages.find(500)->second : config.root + "/errors/500.html";
        std::string content = readFile(error_page);
        if (content.empty()) content = "<html><body><h1>500 Internal Server Error - Cannot Save File</h1></body></html>";
        std::ostringstream response;
        response << "HTTP/1.1 500 Internal Server Error\r\n"
                << "Content-Type: text/html\r\n"
                << "Content-Length: " << content.length() << "\r\n"
                << "Connection: close\r\n"
                << "\r\n"
                << content;
        return response.str();
    }

    // Escribir el cuerpo en el archivo
    ssize_t bytes_written = write(fd, body.c_str(), body.length());
    close(fd);
    if (bytes_written != static_cast<ssize_t>(body.length())) {
        std::cerr << "ERROR: Failed to write file: " << filepath 
                  << ", bytes_written: " << bytes_written 
                  << ", expected: " << body.length() 
                  << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl << std::flush;
        status_code = 500;
        std::string error_page = config.error_pages.find(500) != config.error_pages.end() ? config.root + config.error_pages.find(500)->second : config.root + "/errors/500.html";
        std::string content = readFile(error_page);
        if (content.empty()) content = "<html><body><h1>500 Internal Server Error - Cannot Save File</h1></body></html>";
        std::ostringstream response;
        response << "HTTP/1.1 500 Internal Server Error\r\n"
                << "Content-Type: text/html\r\n"
                << "Content-Length: " << content.length() << "\r\n"
                << "Connection: close\r\n"
                << "\r\n"
                << content;
        return response.str();
    }

    std::cerr << "DEBUG: File saved successfully: " << filepath << std::endl << std::flush;

    // Generar respuesta
    std::string location_uri = request.getUri();
    std::string content = "<html><body><h1>201 Created - File Uploaded</h1></body></html>";
    std::ostringstream response;
    response << "HTTP/1.1 201 Created\r\n"
            << "Content-Type: text/html\r\n"
            << "Content-Length: " << content.length() << "\r\n"
            << "Location: " << location_uri << "\r\n"
            << "Connection: close\r\n"
            << "\r\n"
            << content;
    return response.str();
}

std::string Response::handleRequest() {  // Main method to handle HTTP requests
    static SessionManager session_manager;  // Static session manager for persistence
    std::cerr << "DEBUG: Handling request for method: " << request.getMethod() << ", URI: " << request.getUri() << std::endl << std::flush;
    const LocationConfig* location = findLocation(request.getUri());  // Find matching location config
    std::string path = resolvePath(location);  // Resolve file system path

    // Manejar sesión
    std::string session_id;  // Session identifier
    std::string cookie_header = request.getHeader("Cookie");  // Get cookie header
    size_t pos = cookie_header.find("session_id=");  // Look for session cookie
    if (pos != std::string::npos) {  // If session cookie found
        size_t start = pos + 11;  // Start after "session_id="
        size_t end = cookie_header.find(";", start);  // Find end of cookie value
        if (end == std::string::npos) end = cookie_header.length();  // Use end of header if no semicolon
        session_id = cookie_header.substr(start, end - start);  // Extract session ID
        std::cerr << "DEBUG: Parsed session_id from cookie: " << session_id << std::endl << std::flush;
        int visit_count = session_manager.incrementVisit(session_id);  // Increment visit count
        if (visit_count == 0) {  // If session not found
            std::cerr << "DEBUG: Invalid session_id, creating new session" << std::endl << std::flush;
            session_id = session_manager.createSession();  // Create new session
        }
    } else {  // No session cookie found
        session_id = session_manager.createSession();  // Create new session
    }
    std::cerr << "DEBUG: Session ID: " << session_id << ", Visit count: " << session_manager.getVisitCount(session_id) << std::endl << std::flush;

    std::ostringstream visit_count_str;  // Convert visit count to string
    visit_count_str << session_manager.getVisitCount(session_id);
    #ifdef _POSIX_C_SOURCE  // POSIX environment variable setting
    setenv("VISIT_COUNT", visit_count_str.str().c_str(), 1);
    #else  // Non-POSIX environment variable setting
    std::string env_var = "VISIT_COUNT=" + visit_count_str.str();
    putenv(const_cast<char*>(env_var.c_str()));
    #endif

    // Verificar ubicación
    if (!location) {  // If no matching location found
        std::cerr << "DEBUG: No matching location for URI: " << request.getUri() << std::endl << std::flush;
        status_code = 404;  // Set 404 Not Found status
        std::string error_page = config.error_pages.find(404) != config.error_pages.end() ? config.root + config.error_pages.find(404)->second : config.root + "/errors/404.html";  // Get error page
        std::string content = readFile(error_page);  // Read error page content
        if (content.empty()) content = "<html><body><h1>404 Not Found - No Matching Location</h1></body></html>";  // Default error content
        std::ostringstream response;  // Build HTTP response
        response << "HTTP/1.1 404 Not Found\r\n"
                << "Content-Type: text/html\r\n"
                << "Content-Length: " << content.length() << "\r\n"
                << "Set-Cookie: session_id=" << session_id << "; Path=/\r\n"
                << "Connection: close\r\n"
                << "\r\n"
                << content;
        return response.str();  // Return 404 response
    }

    // Verificar métodos permitidos
    if (!location->methods.empty()) {  // If location has method restrictions
        bool method_allowed = false;  // Flag for method permission
        for (size_t i = 0; i < location->methods.size(); ++i) {  // Check each allowed method
            if (location->methods[i] == request.getMethod()) {  // If method matches
                method_allowed = true;  // Set permission flag
                break;  // Exit loop
            }
        }
        if (!method_allowed) {  // If method not allowed
            std::cerr << "DEBUG: Method not allowed: " << request.getMethod() << " for " << request.getUri() << std::endl << std::flush;
            status_code = 405;  // Set 405 Method Not Allowed status
            std::string error_page = config.error_pages.find(405) != config.error_pages.end() ? config.root + config.error_pages.find(405)->second : config.root + "/errors/405.html";  // Get error page
            std::string content = readFile(error_page);  // Read error page content
            if (content.empty()) content = "<html><body><h1>405 Method Not Allowed</h1></body></html>";  // Default error content
            std::ostringstream response;  // Build HTTP response
            response << "HTTP/1.1 405 Method Not Allowed\r\n"
                    << "Content-Type: text/html\r\n"
                    << "Content-Length: " << content.length() << "\r\n"
                    << "Set-Cookie: session_id=" << session_id << "; Path=/\r\n"
                    << "Connection: close\r\n"
                    << "\r\n"
                    << content;
            return response.str();  // Return 405 response
        }
    }

    // Manejar POST con upload_path
    if (request.getMethod() == "POST" && !location->upload_path.empty()) {  // Handle POST requests with upload capability
        size_t max_body_size = location->client_max_body_size > 0 ? location->client_max_body_size : config.client_max_body_size;  // Get body size limit
        if (request.getBody().length() > max_body_size) {  // Check if body exceeds limit
            std::cerr << "DEBUG: Request body size (" << request.getBody().length() << ") exceeds client_max_body_size (" << max_body_size << ")" << std::endl << std::flush;
            status_code = 413;  // Set 413 Payload Too Large status
            std::string error_page = config.error_pages.find(413) != config.error_pages.end() ? config.root + config.error_pages.find(413)->second : config.root + "/errors/413.html";  // Get error page
            std::string content = readFile(error_page);  // Read error page content
            if (content.empty()) content = "<html><body><h1>413 Payload Too Large</h1></body></html>";  // Default error content
            std::ostringstream response;  // Build HTTP response
            response << "HTTP/1.1 413 Payload Too Large\r\n"
                    << "Content-Type: text/html\r\n"
                    << "Content-Length: " << content.length() << "\r\n"
                    << "Set-Cookie: session_id=" << session_id << "; Path=/\r\n"
                    << "Connection: close\r\n"
                    << "\r\n"
                    << content;
            return response.str();  // Return 413 response
        }
        return handleUpload(location->upload_path);  // Delegate to upload handler
    }

    // Manejar DELETE
    if (request.getMethod() == "DELETE") {  // Handle DELETE requests
        std::string dir_path = path.substr(0, path.find_last_of('/'));  // Get directory path
        if (access(dir_path.c_str(), W_OK) != 0) {  // Check write permission on directory
            std::cerr << "ERROR: No write permission for directory: " << dir_path 
                      << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl << std::flush;
            status_code = 403;  // Set 403 Forbidden status
            std::string error_page = config.error_pages.find(403) != config.error_pages.end() ? config.root + config.error_pages.find(403)->second : config.root + "/errors/403.html";  // Get error page
            std::string content = readFile(error_page);  // Read error page content
            if (content.empty()) content = "<html><body><h1>403 Forbidden - No Write Permission</h1></body></html>";  // Default error content
            std::ostringstream response;  // Build HTTP response
            response << "HTTP/1.1 403 Forbidden\r\n"
                    << "Content-Type: text/html\r\n"
                    << "Content-Length: " << content.length() << "\r\n"
                    << "Set-Cookie: session_id=" << session_id << "; Path=/\r\n"
                    << "Connection: close\r\n"
                    << "\r\n"
                    << content;
            return response.str();  // Return 403 response
        }

        if (!fileExists(path)) {
            std::cerr << "DEBUG: Path does not exist: " << path << std::endl << std::flush;
            status_code = 404;
            std::string error_page = config.error_pages.find(404) != config.error_pages.end() ? config.root + config.error_pages.find(404)->second : config.root + "/errors/404.html";
            std::string content = readFile(error_page);
            if (content.empty()) content = "<html><body><h1>404 Not Found - Resource Missing</h1></body></html>";
            std::ostringstream response;
            response << "HTTP/1.1 404 Not Found\r\n"
                    << "Content-Type: text/html\r\n"
                    << "Content-Length: " << content.length() << "\r\n"
                    << "Set-Cookie: session_id=" << session_id << "; Path=/\r\n"
                    << "Connection: close\r\n"
                    << "\r\n"
                    << content;
            return response.str();
        }

        if (isDirectory(path)) {
            std::cerr << "DEBUG: Path is a directory: " << path << std::endl << std::flush;
            status_code = 403;
            std::string error_page = config.error_pages.find(403) != config.error_pages.end() ? config.root + config.error_pages.find(403)->second : config.root + "/errors/403.html";
            std::string content = readFile(error_page);
            if (content.empty()) content = "<html><body><h1>403 Forbidden - Cannot Delete Directory</h1></body></html>";
            std::ostringstream response;
            response << "HTTP/1.1 403 Forbidden\r\n"
                    << "Content-Type: text/html\r\n"
                    << "Content-Length: " << content.length() << "\r\n"
                    << "Set-Cookie: session_id=" << session_id << "; Path=/\r\n"
                    << "Connection: close\r\n"
                    << "\r\n"
                    << content;
            return response.str();
        }

        if (unlink(path.c_str()) == 0) {  // Attempt to delete the file
            std::cerr << "DEBUG: File deleted successfully: " << path << std::endl << std::flush;
            status_code = 200;  // Set 200 OK status
            std::string content = "<html><body><h1>200 OK - File Deleted</h1></body></html>";  // Success message
            std::ostringstream response;  // Build HTTP response
            response << "HTTP/1.1 200 OK\r\n"
                    << "Content-Type: text/html\r\n"
                    << "Content-Length: " << content.length() << "\r\n"
                    << "Set-Cookie: session_id=" << session_id << "; Path=/\r\n"
                    << "Connection: close\r\n"
                    << "\r\n"
                    << content;
            return response.str();  // Return success response
        } else {  // If deletion failed
            std::cerr << "ERROR: Failed to delete file: " << path 
                      << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl << std::flush;
            status_code = 500;  // Set 500 Internal Server Error status
            std::string error_page = config.error_pages.find(500) != config.error_pages.end() ? config.root + config.error_pages.find(500)->second : config.root + "/errors/500.html";  // Get error page
            std::string content = readFile(error_page);  // Read error page content
            if (content.empty()) content = "<html><body><h1>500 Internal Server Error - Delete Failed</h1></body></html>";  // Default error content
            std::ostringstream response;  // Build HTTP response
            response << "HTTP/1.1 500 Internal Server Error\r\n"
                << "Content-Type: text/html\r\n"
                << "Content-Length: " << content.length() << "\r\n"
                << "Set-Cookie: session_id=" << session_id << "; Path=/\r\n"
                << "Connection: close\r\n"
                << "\r\n"
                << content;
            return response.str();  // Return error response
        }
    }

    // Manejar GET y otros métodos
    if (!fileExists(path)) {  // Check if requested resource exists
        std::cerr << "DEBUG: Path does not exist: " << path << std::endl << std::flush;
        status_code = 404;  // Set 404 Not Found status
        std::string error_page = config.error_pages.find(404) != config.error_pages.end() ? config.root + config.error_pages.find(404)->second : config.root + "/errors/404.html";  // Get error page
        std::string content = readFile(error_page);  // Read error page content
        if (content.empty()) content = "<html><body><h1>404 Not Found - Resource Missing</h1></body></html>";  // Default error content
        std::ostringstream response;
        response << "HTTP/1.1 404 Not Found\r\n"
                << "Content-Type: text/html\r\n"
                << "Content-Length: " << content.length() << "\r\n"
                << "Set-Cookie: session_id=" << session_id << "; Path=/\r\n"
                << "Connection: close\r\n"
                << "\r\n"
                << content;
        return response.str();
    }

    if (isDirectory(path)) {
        std::string uri = request.getUri();
        std::string index_path = path + (location && !location->index.empty() ? location->index : config.index);
        if (uri.empty() || uri == "/" || uri[uri.length() - 1] == '/') {
            if (fileExists(index_path)) {
                std::cerr << "DEBUG: Serving index file: " << index_path << std::endl << std::flush;
                path = index_path;
            } else if (location && location->directory_listing) {
                std::cerr << "DEBUG: Generating directory listing for: " << path << std::endl << std::flush;
                std::string content = generateDirectoryListing(path, uri);
                if (content.empty()) {
                    status_code = 403;
                    std::string error_page = config.error_pages.find(403) != config.error_pages.end() ? config.root + config.error_pages.find(403)->second : config.root + "/errors/403.html";
                    std::string content = readFile(error_page);
                    if (content.empty()) content = "<html><body><h1>403 Forbidden - Directory Listing Failed</h1></body></html>";
                    std::ostringstream response;
                    response << "HTTP/1.1 403 Forbidden\r\n"
                            << "Content-Type: text/html\r\n"
                            << "Content-Length: " << content.length() << "\r\n"
                            << "Set-Cookie: session_id=" << session_id << "; Path=/\r\n"
                            << "Connection: close\r\n"
                            << "\r\n"
                            << content;
                    return response.str();
                }
                std::ostringstream response;
                response << "HTTP/1.1 200 OK\r\n"
                        << "Content-Type: text/html\r\n"
                        << "Content-Length: " << content.length() << "\r\n"
                        << "Set-Cookie: session_id=" << session_id << "; Path=/\r\n"
                        << "Connection: close\r\n"
                        << "\r\n"
                        << content;
                return response.str();
            } else {
                std::cerr << "DEBUG: Index file not found and directory listing disabled: " << index_path << std::endl << std::flush;
                status_code = 403;
                std::string error_page = config.error_pages.find(403) != config.error_pages.end() ? config.root + config.error_pages.find(403)->second : config.root + "/errors/403.html";
                std::string content = readFile(error_page);
                if (content.empty()) content = "<html><body><h1>403 Forbidden - Directory Access Denied</h1></body></html>";
                std::ostringstream response;
                response << "HTTP/1.1 403 Forbidden\r\n"
                        << "Content-Type: text/html\r\n"
                        << "Content-Length: " << content.length() << "\r\n"
                        << "Set-Cookie: session_id=" << session_id << "; Path=/\r\n"
                        << "Connection: close\r\n"
                        << "\r\n"
                        << content;
                return response.str();
            }
        } else {
            std::cerr << "DEBUG: Directory redirect: " << path << std::endl << std::flush;
            std::ostringstream response;
            response << "HTTP/1.1 307 Temporary Redirect\r\n"
                    << "Location: " << uri << "/\r\n"
                    << "Content-Length: 0\r\n"
                    << "Set-Cookie: session_id=" << session_id << "; Path=/\r\n"
                    << "Connection: close\r\n"
                    << "\r\n";
            return response.str();
        }
    }

    if (location && !location->redirect.empty()) {
        std::cerr << "DEBUG: Redirecting to: " << location->redirect << std::endl << std::flush;
        std::ostringstream response;
        response << "HTTP/1.1 301 Moved Permanently\r\n"
                << "Location: " << location->redirect << "\r\n"
                << "Content-Length: 0\r\n"
                << "Set-Cookie: session_id=" << session_id << "; Path=/\r\n"
                << "Connection: close\r\n"
                << "\r\n";
        return response.str();
    }

    if (location && !location->cgi_paths.empty()) {
        std::string extension;
        size_t dot_pos = path.find_last_of(".");
        if (dot_pos != std::string::npos && dot_pos < path.length() - 1) {
            extension = path.substr(dot_pos);
            std::cerr << "DEBUG: Detected file extension: " << extension << std::endl << std::flush;
        } else {
            std::cerr << "DEBUG: No file extension found for path: " << path << std::endl << std::flush;
        }

        std::map<std::string, std::string>::const_iterator it = location->cgi_paths.find(extension);
        if (it != location->cgi_paths.end() && fileExists(path)) {
            std::string cgi_interpreter = it->second;
            std::cerr << "DEBUG: Detected CGI request for path: " << path << ", cgi_interpreter: " << cgi_interpreter << std::endl << std::flush;
            std::cerr << "DEBUG: Starting CGI execution, clearing any previous output" << std::endl << std::flush;
            CGI cgi(request, *location, config, port);
            std::pair<std::string, int> cgi_result = cgi.execute(path);
            std::string cgi_output = cgi_result.first;
            status_code = cgi_result.second;
            std::cerr << "DEBUG: CGI executed with status: " << status_code << ", output length: " << cgi_output.length() << std::endl << std::flush;
            std::ostringstream response;
            if (status_code == 200) {
                response << "HTTP/1.1 200 OK\r\n";
            } else {
                response << "HTTP/1.1 500 Internal Server Error\r\n";
            }
            response << "Content-Type: " << getMimeType(path) << "\r\n"
                     << "Content-Length: " << cgi_output.length() << "\r\n"
                     << "Set-Cookie: session_id=" << session_id << "; Path=/\r\n"
                     << "Connection: close\r\n"
                     << "\r\n"
                     << cgi_output;
            return response.str();
        } else {
            std::cerr << "DEBUG: No CGI interpreter found for extension: " << extension << " or file does not exist" << std::endl << std::flush;
        }
    }

    std::string content = readFile(path);
    if (content.empty()) {
        std::cerr << "ERROR: Failed to read file: " << path << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl << std::flush;
        status_code = 500;
        std::string error_page = config.error_pages.find(500) != config.error_pages.end() ? config.root + config.error_pages.find(500)->second : config.root + "/errors/500.html";
        std::string content = readFile(error_page);
        if (content.empty()) content = "<html><body><h1>500 Internal Server Error</h1></body></html>";
        std::ostringstream response;
        response << "HTTP/1.1 500 Internal Server Error\r\n"
                << "Content-Type: text/html\r\n"
                << "Content-Length: " << content.length() << "\r\n"
                << "Set-Cookie: session_id=" << session_id << "; Path=/\r\n"
                << "Connection: close\r\n"
                << "\r\n"
                << content;
        return response.str();
    }
    std::cerr << "DEBUG: Serving static file: " << path << std::endl << std::flush;
    std::ostringstream response;
    response << "HTTP/1.1 200 OK\r\n"
            << "Content-Type: " << getMimeType(path) << "\r\n"
            << "Content-Length: " << content.length() << "\r\n"
            << "Set-Cookie: session_id=" << session_id << "; Path=/\r\n"
            << "Connection: close\r\n"
            << "\r\n"
            << content;
    return response.str();
}