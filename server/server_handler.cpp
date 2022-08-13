#include "server_handler.h"

Server_handler::Server_handler(int port) {
    server = new Server(port);
}

void Server_handler::run() {
    FlowerPoint& flowerPoint = server->receiveFlowerPoint();

    while (!server->isCommOver()) {
        server->sendClassification(flowerPoint, 3, new EuclideanDistance);
        flowerPoint = server->receiveFlowerPoint();
    }
}

void Server_handler::close() {
    server->closeServer();
}