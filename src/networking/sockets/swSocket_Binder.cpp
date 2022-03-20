//
// Created by joaoa on 20/03/2022.
//

#include "swSocket_Binder.h"

// Constructor
swlib::swSocket_Binder::swSocket_Binder(short domain, int service, int protocol, int port, u_long iface)
: swSocket(domain, service, protocol, port, iface)
{
    //  Establish network connection
    set_connection(sw_connect(get_sock(), get_address()));
    test_connection(get_connection());
}

// Definition of sw_connect() virtual function
int swlib::swSocket_Binder::sw_connect(int sock, struct sockaddr_in address)
{
    return bind(sock, (struct sockaddr *)&address, sizeof(address));
}
