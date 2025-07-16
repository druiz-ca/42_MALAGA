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
    ifstream file(path);
    if (!file.is_open())
        return "no se pudo abrir";
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
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

        // solicitud de archivo
        string requested_file = "./public/index.html";
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
        else{

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