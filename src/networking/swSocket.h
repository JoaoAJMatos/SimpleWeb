//
// Created by joaoa on 20/03/2022.
//

#ifndef SIMPLEWEB_SWSOCKET_H
#define SIMPLEWEB_SWSOCKET_H

#pragma comment(lib, "ws2_32.lib")

#include <winsock2.h>
#include <WS2tcpip.h>
#include <tchar.h>

#include <iostream>

// Message buffer
#define Buffer 1500

namespace swlib
{
    class swSocket {
    private:
        // Private variables
        WSADATA wsa;
        SOCKET s;
        struct sockaddr_in server;
        int iResult;
        const char message[Buffer] = "This message being displayed to you, is sent from a C++ Winsocket HTTP server";
        char reply[Buffer];

    public:
        // Constructor
        swSocket();

        // Public Functions
        int swInit();
    };
}



#endif //SIMPLEWEB_SWSOCKET_H
