//
// Created by joaoa on 20/03/2022.
//

#include "swListening_Socket.h"

/* CONSTRUCTORS */
swlib::swListening_Socket::swListening_Socket(int domain, int service, int protocol, int port, u_long iface, int bklg)
: swSocket_Binder(domain, service, protocol, port, iface)
{
    // Set backlog variable
    backlog = bklg;
    // Start listening to the network using listen() from winsock2.h
    start_listening();
    // Confirm the connection was successful
    test_connection(listening);
}

/* MUTATORS */
void swlib::swListening_Socket::start_listening() {
    listening = listen(get_sock(), backlog);
}


/* GETTERS */
int swlib::swListening_Socket::get_backlog() const {
    return backlog;
}

int swlib::swListening_Socket::get_listening() const {
    return listening;
}


