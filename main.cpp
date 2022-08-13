#include <iostream>
#include "server/server_handler.h"

int main() {
    Server_handler* serverHandler = new Server_handler();
    serverHandler->run();
    serverHandler->close();

    delete serverHandler;
}
