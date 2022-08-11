#include "server/server.h"
#include "classifier/flower/flowerReader.h"

Server::Server(int server_port) {
    this->server_port = server_port;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(server_socket, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }

    if (listen(server_socket, 5) < 0) {
        perror("error listening to a socket");
    }

    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    this->client_sock = accept(server_socket,  (struct sockaddr *) &client_sin,  &addr_len);

    if (client_sock < 0) {
        perror("error accepting client");
    }
}

FlowerPoint& Server::receiveFlowerPoint() const {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        // connection is closed
    }
    else if (read_bytes < 0) {
        // error
    }
    else {
        string line(buffer);
        return *(detectFlowerPoint(line);
    }
}

void Server::closeSever() const {
    close(server_socket);
}