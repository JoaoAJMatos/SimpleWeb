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
        /* MEMBER VARIABLES */
        // Once instantiated, sock contains the address of a socket object on the network.
        // This should be a non-negative number.
        int sock;
        // The address variable is a struct that contains information about the protocol,
        // type, and interface of a given socket. These parameters are specified and set
        // in the constructor.
        struct sockaddr_in address;

        WSADATA wsa;

    public:
        /* CONSTRUCTORS */
        // A parameterized constructor is required to instantiate the class.
        swSocket(int domain, int service, int protocol, int port, u_long iface);

        /* VIRTUAL FUNCTIONS */
        // This function connects to the network using either bind() or connect() from winsock2.h
        virtual int sw_connect(int sock, struct sockaddr_in address) = 0;

        /* TESTERS */
        // This function exits the program if the connection is not properly established.
        // This should be checked frequently.
        static void test_connection(int);

        /* GETTERS */
        struct sockaddr_in get_address();
        int get_sock() const;
    };
}

#endif //SIMPLEWEB_SWSOCKET_H
