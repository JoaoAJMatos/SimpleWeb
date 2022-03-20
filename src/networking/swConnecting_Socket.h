//
// Created by joaoa on 20/03/2022.
//

#ifndef SIMPLEWEB_SWCONNECTING_SOCKET_H
#define SIMPLEWEB_SWCONNECTING_SOCKET_H

#include "swSocket.h"

namespace swlib
{
    class swConnecting_Socket: public swSocket
    {
    public:
        // Constructor
        swConnecting_Socket(short domain, int service, int protocol, int port, u_long iface);

        // Virtual function from parent
        int sw_connect(SOCKET sock, struct sockaddr_in address) override;
    };
}


#endif //SIMPLEWEB_SWCONNECTING_SOCKET_H
