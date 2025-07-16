#ifndef SERVER_HPP
#define SERVER_HPP

#include "Config.hpp"
#include "Request.hpp"
#include "Response.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <vector>
#include <string>
#include <cstdlib>

class Server {
	// This class is responsible for setting up and managing a server.
	// It uses the Config class to read configuration settings from a file.
	// The server listens for incoming connections and handles them using select.
	// It supports persistent connections and is designed to be efficient and scalable.
	public:
		Server(const ServerConfig& conf);
		// Constructor that takes a ServerConfig object to initialize the server.
		~Server();
		// Destructor to clean up resources when the server is no longer needed.
		void run();
		// Starts the server and begins listening for incoming connections.

	private:
		static const int KEEP_ALIVE_TIMEOUT = 30; 
		// Timeout in 30 seconds for keep-alive connections
		struct Client {
			// This struct represents a client connected to the server.
			int fd;
			// The file descriptor for the client socket.
			std::string buffer;
			// A buffer to store incoming data from the client.
			time_t last_activity;
			// The last time the client was active.
		};

    int sockfd;
	// The file descriptor for the server socket.
    ServerConfig config;
	// The configuration settings for the server.
    std::vector<Client> clients;
	// A vector to store connected clients.
};

#endif