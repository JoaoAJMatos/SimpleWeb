//
// Created by joaoa on 20/03/2022.
//

#include "swConnecting_Socket.h"

// Constructor
swlib::swConnecting_Socket::swConnecting_Socket(short domain, int service, int protocol, int port, u_long iface): swSocket(domain, service, protocol, port, iface)
{
    //  Establish network connection
    set_connection(sw_connect(get_sock(), get_address()));
    test_connection(get_connection());
}

// Definition of sw_connect() virtual function
int swlib::swConnecting_Socket::sw_connect(SOCKET sock, struct sockaddr_in address) {
    return connect(sock, (struct sockaddr *)&address, sizeof(address));
}


