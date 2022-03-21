//
// Created by joaoa on 20/03/2022.
//
// swSocket_Binder is the first child of swSocket, created as the basis for a server object.
//
// This class implements a call to the bind() function of  sockets as a
// definition of the sw_connect() virtual function from swSocket.h
//
// (It defines the sw_connect() function from swSocket to utilize the bind function from winsock2.h)

#ifndef SIMPLEWEB_SWSOCKET_BINDER_H
#define SIMPLEWEB_SWSOCKET_BINDER_H

#include "swSocket.h"

namespace swlib
{
    class swSocket_Binder: public swSocket
    {
    private:
        /* MEMBER VARIABLES */
        // The binding variable stores the value 0 if the socket binding is successful
        int binding;

        /* MEMBER FUNCTIONS */
        // Virtual function from parent
        int sw_connect(int sock, struct sockaddr_in address) override;

    public:
        /* CONSTRUCTOR */
        // A parameterized constructor is required for this class
        swSocket_Binder(int domain, int service, int protocol, int port, u_long iface);

        /* GETTERS */
        int get_binding() const;
    };
}


#endif //SIMPLEWEB_SWSOCKET_BINDER_H
