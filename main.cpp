#include <iostream>
#include "server/server_handler.h"

/**
 * The main function for the server.
 * it creates a server_handler object, and runs it.
 * @param argc - number of arguments.
 * @param argv - array of arguments, may contain the path to the flower data csv file
 * (if not given, the default path is used - "data/flower_data.csv").
 * @return 0 (the default return value of the main function)
 */
int main(int argc, char *argv[]) {
    Server *server = nullptr;
    if (argc > 1) {
        server = new Server(argv[1]);
    } else {
        server = new Server();
    }

    Server_handler* serverHandler = new Server_handler(server);
    serverHandler->connect();
    serverHandler->run();
    serverHandler->close();

    delete serverHandler;
    delete server;
}
