#include <iostream>
#include "server/server_handler.h"

/**
 * The main function for the server.
 * it creates a server_handler object, and runs it.
 * @param argc - number of arguments.
 * @param argv - array of arguments (not used).
 * @return 0 (the default return value of the main function)
 */
int main() {
    Server_handler* serverHandler = new Server_handler();
    serverHandler->connect();
    serverHandler->run();
    serverHandler->close();

    delete serverHandler;
}
