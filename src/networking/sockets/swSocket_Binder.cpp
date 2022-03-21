//
// Created by joaoa on 20/03/2022.
//

#include "swSocket_Binder.h"

/* CONSTRUCTOR */
swlib::swSocket_Binder::swSocket_Binder(int domain, int service, int protocol, int port, u_long iface)
: swSocket(domain, service, protocol, port, iface)
{
    //  Establish network connection
    sw_connect(sw_connect(get_sock(), get_address()));
    // Test the connection
    test_connection(binding);
}

/* VIRTUAL FUNCTION OVERRIDE */
// Definition of sw_connect() virtual function
// This function overrides the swSocket.h's sw_connect() and defines it to use
// the bind() function from winsock2.h
int swlib::swSocket_Binder::sw_connect(int sock, struct sockaddr_in address)
{
    binding = bind(sock, (struct sockaddr *)&address, sizeof(address));
}

/* GETTERS */
int swlib::swSocket_Binder::get_binding() const {
    return binding;
}
