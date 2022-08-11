#ifndef ASS_TWO_SERVER_H
#define ASS_TWO_SERVER_H

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "classifier/flower/flower.h"

class Server {

    private:
        int server_port;
        int server_socket;
        int client_sock;

    public:
        Server(int port);
        FlowerPoint& receiveFlowerPoint();
        void sendClassification(Flower& flower);
        void close();
};

#endif //ASS_TWO_SERVER_H
