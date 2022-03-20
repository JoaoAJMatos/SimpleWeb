//
// Created by joaoa on 20/03/2022.
//

#ifndef SIMPLEWEB_SWSOCKET_H
#define SIMPLEWEB_SWSOCKET_H

#pragma comment(lib, "ws2_32.lib")

#include <winsock2.h>
#include <ws2tcpip.h>
#include <tchar.h>
#include <iostream>

namespace swlib
{
    class swSocket {
    private:
        // Private variables
        int sock;
        int connection;
        struct sockaddr_in address;
        WSADATA wsa;

    public:
        // Constructor
        swSocket(short domain, int service, int protocol, int port, u_long iface);

        // Virtual function to connect to a network
        virtual int sw_connect(int sock, struct sockaddr_in address) = 0;

        // Function to test sockets and connections
        static void test_connection(int);

        // Getter functions
        struct sockaddr_in get_address();
        int get_sock();
        int get_connection();

        // Setter functions
        void set_connection(int con);
    };
}

#endif //SIMPLEWEB_SWSOCKET_H
