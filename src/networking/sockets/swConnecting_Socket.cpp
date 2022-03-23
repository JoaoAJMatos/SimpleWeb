//
// Created by joaoa on 20/03/2022.
//

#include "swConnecting_Socket.h"

/* CONSTRUCTOR */
swlib::swConnecting_Socket::swConnecting_Socket(short domain, int service, int protocol, int port, u_long iface)
: swSocket(domain, service, protocol, port, iface)
{
    //  Establish network connection
    sw_connect(get_sock(), get_address());
    // Test the connection
    test_connection(connection);
}


/* VIRTUAL FUNCTIONS */
// Definition of sw_connect() virtual function
int swlib::swConnecting_Socket::sw_connect(int sock, struct sockaddr_in address) {
    connection = connect(sock, (struct sockaddr *)&address, sizeof(address));
}


/* GETTERS */
int swlib::swConnecting_Socket::get_connection() const {
    return connection;
}


