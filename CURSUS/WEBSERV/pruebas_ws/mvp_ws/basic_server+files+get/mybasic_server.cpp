#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

string tryOpenAndReadFile(const string& path)
{
    ifstream file(path); // convierte el string a ifstream
    if (!file.is_open()) // comprueba si se puede abrir
        return "No se pudo abrir";
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str(); // devuelve el contenido del archivo
}


string getRequestFile(const string& request)
{
    // busca GET en la request
    // luego lo salta para posicionarse en el inicio del nombre de archivo solicitado
    // el GET se genera automáticamente al hacer una solicitud HTTP
    size_t start = request.find("GET ") + 4;

    // delimita el final en el 1er espacio pq luego hay (HTTP/1.1)
    size_t end = request.find(" ", start);

    // Extrae la cadena con la request (pedido)
    string file = request.substr(start, end - start);
    
    return "./public" + file;
}

int main()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        // AF_INET -> IPv4 (conexexiones estándar)
        // SOCK_STREAM -> protocolo TCP

    int opt = 1; // 1 representa "habilitar"
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
        // SOL_SOCKET -> configuración a nivel del socket
        // SO_REUSADOR -> para reutilizar la dir y el puerto del socket
            // sino, el puerto se mantiene ocupado durante un tiempo inutilizable
    
    struct sockaddr_in server_addres; // DEclaro estructura 
    memset(&server_addres, 0, sizeof(server_addres)); // La limpio
    server_addres.sin_family = AF_INET; // IPv4
    server_addres.sin_addr.s_addr = INADDR_ANY; // escucha desde cualquier IP
    server_addres.sin_port = htons(8080); // el puerto donde escuchará

    // bind->unir (la conf del servidor al fd)
    bind(server_fd, (struct sockaddr*)&server_addres, sizeof(server_addres));
    listen(server_fd, 10);
        // 10 -> el máx de num de conexiones pendientes que acepta
        // en el 1024 no va!?
    while (1)
    {
        struct sockaddr_in client_addres; // para guardar la IP del cliente
        socklen_t client_len = sizeof(client_addres);

        int client_fd;
        // accept -> queda esperando a q un cliente se conecte
        client_fd = accept(server_fd, (struct sockaddr*)&client_addres, &client_len);
        // ------------------------------------------------------------------------ //
        // Leer solicitud de archivo del cliente
        char buffer[1024] = {0};

        // carga el archivo que pido (localhost:8080/index.html) en el buffer
        read(client_fd, buffer, sizeof(buffer) - 1);
            // read almacena en buffer: (cuando escribes http://localhost:8080/index.html)
                // - el método: GET
                // - el host: localhost:8080
                // - tipo de conexion: keep-alive

        string request(buffer); // convierte buffer(char) a string

        // extraer el nombre del archivo solicitado de la request (GET index.html HTTP.....)
        string requested_file = getRequestFile(request);

        // intenta abrir el archivo, si lo consige devuelve el contenido
        string file_content = tryOpenAndReadFile(requested_file);
        string response;

        if (file_content.empty())
        {
            response = 
                "HTTP/1.1 404 Not Found\r\n"
                "Content-Type: text/html\r\n"
                "Content-Length: 13\r\n"
                "\r\n"
                "<h1>404</h1>";
        }else{
            response =
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/html\r\n"
                "Content-Length: " + to_string(file_content.length()) + "\r\n"
                "\r\n" + 
                file_content;
            // si modifico el html se cambia el directo pero no el .cpp!!
            // hay que kill el proceso anterior y volver a cargar
        }
        send(client_fd, response.c_str(), response.length(), 0);
        close(client_fd);
    }
    close(server_fd);
}