//
// Created by joaoa on 20/03/2022.
//

#include "swSocket.h"

/* CONSTRUCTOR */
swlib::swSocket::swSocket(int domain, int service, int protocol, int port, u_long iface)
{
    // Define address structure
    address.sin_family = domain;
    address.sin_port = htons(port); // Convert integer byte order to network using htons()
    address.sin_addr.s_addr = htonl(iface);

    // Attempt to initialize winsock
    WORD wVersionRequested = MAKEWORD(2, 2);
    int iResult = WSAStartup(wVersionRequested, &wsa);

    if (iResult != 0)
    {
        std::cout << "WSAStartup failed with error: " <<  iResult << std::endl;
        exit(EXIT_FAILURE);
    }

    // Establish socket
    sock = socket(domain, service, protocol);
    test_connection(sock);
}

/* VIRTUAL FUNCTIONS */
// Test conection virtual function
void swlib::swSocket::test_connection(int item_to_test)
{
    // Confirm that either the socket or connection have been properly established
    if (item_to_test < 0)
    {
        perror("Failed to connect...");
        exit(EXIT_FAILURE);
    }
}

/* GETTERS */
// Returns this socket's address
struct sockaddr_in swlib::swSocket::get_address() {
    return address;
}

// Return this socket
int swlib::swSocket::get_sock() const {
    return sock;
}