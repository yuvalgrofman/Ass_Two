#include "server_handler.h"

Server_handler::Server_handler(Server *server) {
    this->server = server;
}

void Server_handler::connect() {
    server->connect();
}

void Server_handler::run() {
    Distance* d = new EuclideanDistance();

    while (!server->isCommOver()) {
        FlowerPoint& flowerPoint = server->receiveFlowerPoint();
        if (!server->isCommOver())
            server->sendClassification(flowerPoint, 3, d);
        delete &flowerPoint;
    }

    delete d;
}

void Server_handler::close() {
    server->closeServer();
}