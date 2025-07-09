#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

string readFile(const string& path)
{
    string path_file;
    path_file = path;
    if (path_file == "about.html")
        return "about";

    ifstream file(path); // convierte el string a ifstream
    if (!file.is_open())
        return "no se pudo abrir";
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

string getRequestFile(const string& request)
{
    size_t start = request.find("GET ") + 4;
    size_t end = request.find(" ", start);

    string file = request.substr(start, end - start);
    
    return "./public" + file;
}

int main()
{
    int server_fd;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
        // AF_INET -> IPv4 (conexexiones estándar)
        // SOCK_STREAM -> protocolo TCP

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
        // SOL_SOCKET -> configuración a nivel del socket
        // SO_REUSADOR -> para reutilizar la dir y el puerto del socket
    
    struct sockaddr_in server_addres;
    memset(&server_addres, 0, sizeof(server_addres));
    server_addres.sin_family = AF_INET; // IPv4
    server_addres.sin_addr.s_addr = INADDR_ANY; // escucha desde cualquier IP
    server_addres.sin_port = htons(8080); // el puerto donde escuchará

    // bind->unir
    bind(server_fd, (struct sockaddr*)&server_addres, sizeof(server_addres));

    listen(server_fd, 10);
        // 10 -> el máx de num de conexiones pendientes que acepta

    cout << "el servidor esta escuchando en el puerto 8080" << endl;
        // en el 1024 no va!?

    while (1)
    {
        struct sockaddr_in client_addres;
        socklen_t client_len = sizeof(client_addres);

        int client_fd;
        client_fd = accept(server_fd, (struct sockaddr*)&client_addres, &client_len);

        cout << "nuevo cliente conectado" << endl;
        // ------------------------------------------------------------------------ //

        // Leer solicitud de archivo del cliente
        char buffer[1024] = {0};

        // carga el archivo que pido (localhost:8080/index.html) en el buffer
        read(client_fd, buffer, sizeof(buffer) -1);
        string request(buffer); // convierte buffer(char) a string

        cout << "Solicitud recibida: " << request << endl;

        // extraer el archivo solicitado de la request
        string requested_file = getRequestFile(request);
        cout << "Archivo solicitado: " << requested_file << endl;

        string file_content = readFile(requested_file);

        string response;

        if (file_content.empty())
        {
            response = 
                "HTTP/1.1 404 Not Found\r\n"
                "Content-Type: text/html\r\n"
                "Content-Length: 13\r\n"
                "\r\n"
                "<h1>404</h1>";
        }
        else if (file_content == "/")
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