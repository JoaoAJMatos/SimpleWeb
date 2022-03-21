//
// Created by joaoa on 21/03/2022.
//

#include "swServer.h"

/* CONSTRUCTOR */
swlib::swServer::swServer(int domain, int service, int protocol, int port, u_long iface, int bklg)
{
    socket = new swListening_Socket(domain, service, protocol, port, iface, bklg);
    // As the socket is going to exist for the duration of the server's life we don't need to worry
    // about memory leaks. Otherwise, we must delete socket.
}

/* GETTERS */
swlib::swListening_Socket *swlib::swServer::get_socket() {
    return socket;
}
