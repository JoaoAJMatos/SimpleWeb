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
        SOCKET sock;
        int connection;
        struct sockaddr_in address;

    public:
        // Constructor
        swSocket(short domain, int service, int protocol, int port, u_long iface);

        // Virtual function to connect to a network
        virtual int sw_connect(SOCKET sock, struct sockaddr_in address) = 0;
        // Function to test sockets and connections
        static void test_connection(int);
        // Getter functions
        struct sockaddr_in get_address();
        SOCKET get_sock() const;
        int get_connection() const;
    };
}



#endif //SIMPLEWEB_SWSOCKET_H
