#ifndef ASS_TWO_SERVER_HANDLER_H
#define ASS_TWO_SERVER_HANDLER_H

#include "server.h"

/**
 * @brief The Server_handler class
 *
 * This class is responsible for handling the server.
 * It creates a server, and handles it.
 */
class Server_handler {

    private:
        Server* server;

    public:
        /**
         * Constructor.
         * @param server - the server to handle.
         */
        Server_handler(int port = 5555);

        /**
         * Connect to the client.
         */
        void connect();

        /**
         * Run the server program, and handle the communication.
         */
        void run();

        /**
         * Close the server.
         */
        void close();

        /**
         * Destructor.
         */
        ~Server_handler();
};

#endif //ASS_TWO_SERVER_HANDLER_H
