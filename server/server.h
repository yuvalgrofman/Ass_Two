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
#include "classifier/classifier.h"
#include "classifier/distances/euclideanDistance.h"

/**
 * @brief The Server class
 *
 * This class represents a server, which is responsible for handling the communication with the client.
 */
class Server {

    private:
        int server_port;
        int server_socket;
        int client_sock;
        bool commOverFlag;
        DataSpace* dataSpace;

    public:
        static const int BUFFER_SIZE = 4096;

        /**
         * Constructor
         * @param port - the port number of the server.
         */
        Server(int port);


        /**
         * Connect to the client.
         */
        void connect();

        /**
         * Receive a flower point from the client.
         * @return the flower point received from the client.
         */
        FlowerPoint& receiveFlowerPoint();

        /**
         * classify a flower, and send the result to the client.
         * @param flower - the flower to classify.
         * @param k - the number of neighbors to use in the KNN algorithm.
         * @param distance - the distance function to use.
         */
        void sendClassification(FlowerPoint& flower, int k, Distance* distance);

        /**
         * Close the server.
         */
        void closeServer() const;

        /**
         * Check if the communication is over.
         * @return
         */
        bool isCommOver();

        /**
         * Destructor.
         */
        ~Server();


};

#endif //ASS_TWO_SERVER_H
