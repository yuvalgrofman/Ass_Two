#include "server/server.h"

Server::Server(string dataSpacePath, int server_port) {
    this->server_port = server_port;
    commOverFlag = false;

    FlowerReader &classifiedReader = *(new FlowerReader(dataSpacePath));
    DataSpaceCreator creator = DataSpaceCreator(classifiedReader);
    dataSpace = &creator.makeDataSpace();

    delete &classifiedReader;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(this->server_port);

    if (bind(server_socket, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }

    if (listen(server_socket, 5) < 0) {
        perror("error listening to a socket");
    }
}

void Server::connect() {
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);

    this->client_sock = accept(server_socket,  (struct sockaddr *) &client_sin,  &addr_len);

    if (client_sock < 0) {
        perror("error accepting client");
    }
}

FlowerPoint& Server::receiveFlowerPoint() {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        commOverFlag = true;
        return *(new FlowerPoint(-1, -1, -1, -1));
    }
    else if (read_bytes < 0) {
        perror("error receiving flower point");
    }
    else {

        int seenR = 0;
        for (int i = 0; i < BUFFER_SIZE; i++) {
            if (seenR) {
                buffer[i] = '\0';
            } else if (buffer[i] == '\r') {
                seenR = 1;
            }
        }

        string line(buffer);

        if (!line.compare("END\r")) {
            commOverFlag = true;
            return *(new FlowerPoint(-1, -1, -1, -1));
        }

        commOverFlag = false;
        return *(detectFlowerPoint(line));
    }
    return *(new FlowerPoint(-1, -1, -1, -1));
}

void Server::sendClassification(FlowerPoint &flower, int k, Distance* distance) {
    FlowerType type = dataSpace->predict(k, flower, *(distance));

    char buffer[BUFFER_SIZE];
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = '\0';
    }

    strcpy(buffer,  FlowerTypeToString(type).c_str());

    int sent_bytes = send(client_sock, buffer, BUFFER_SIZE, 0);

    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}

void Server::closeServer() const {
    close(server_socket);
}

bool Server::isCommOver() {
    return commOverFlag;
}

Server::~Server() {
    delete dataSpace;
}