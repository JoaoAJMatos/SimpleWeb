//
// Created by joaoa on 20/03/2022.
//

#include "swListening_Socket.h"

// Constructor
swlib::swListening_Socket::swListening_Socket(short domain, int service, int protocol, int port, u_long iface, int bklg)
: swSocket_Binder(domain, service, protocol, port, iface)
{
    backlog = bklg;
    start_listening();
    test_connection(listening);
}


void swlib::swListening_Socket::start_listening() {
    listening = listen(get_sock(), backlog);
}
