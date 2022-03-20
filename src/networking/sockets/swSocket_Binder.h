//
// Created by joaoa on 20/03/2022.
//
//
// This class implements a call to the bind() function of  sockets as a
// definition of the sw_connect() virtual function from swSocket.

#ifndef SIMPLEWEB_SWSOCKET_BINDER_H
#define SIMPLEWEB_SWSOCKET_BINDER_H

#include "swSocket.h"

namespace swlib
{
    class swSocket_Binder: public swSocket
    {
    public:
        // Constructor
        swSocket_Binder(short domain, int service, int protocol, int port, u_long iface);

        // Virtual function from parent
        int sw_connect(int sock, struct sockaddr_in address) override;
    };
}


#endif //SIMPLEWEB_SWSOCKET_BINDER_H
