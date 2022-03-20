//
// Created by joaoa on 20/03/2022.
//

#include "swSocket.h"

// Default constructor
swlib::swSocket::swSocket(short domain, int service, int protocol, int port, u_long iface)
{
    // Define address structure
    address.sin_family = domain;
    address.sin_port = htons(port); // Convert integer byte order to network using htons()
    address.sin_addr.s_addr = htonl(iface);

    // Establish socket
    sock = socket(domain, service, protocol);
    test_connection(sock);

    //  Establish network connection
    connection = sw_connect(sock, address);
    test_connection(connection);
}

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

// Getter functions - Begin
struct sockaddr_in swlib::swSocket::get_address() {
    // Returns this socket's address
    return address;
}

SOCKET swlib::swSocket::get_sock() const {
    // Return this socket
    return sock;
}

int swlib::swSocket::get_connection() const {
    // Return this connection
    return connection;
}
// Getter functions - End
