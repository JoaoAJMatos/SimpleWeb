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
    private:
        /* MEMBER VARIABLES */
        // The connection variable will store the result of the connect() function in Winsock2.h, stores the value 0 if no error occur
        int connection;

    public:
        // Constructor
        swConnecting_Socket(short domain, int service, int protocol, int port, u_long iface);

        // Virtual function from parent
        int sw_connect(int sock, struct sockaddr_in address) override;

        /* GETTERS */
        int get_connection() const;
    };
}


#endif //SIMPLEWEB_SWCONNECTING_SOCKET_H
