//
// Created by joaoa on 21/03/2022.
//

#ifndef SIMPLEWEB_SWSERVER_H
#define SIMPLEWEB_SWSERVER_H

#include "../swlib_networking.h"

namespace swlib
{
    class swServer
    {
    private:
        /* MEMBER VARIABLES */
        // (A pointer to swListening_Socket defines a space in memory to store a listening socket, without instantiating it)
        swListening_Socket* socket;

        /* VIRTUAL MEMBER FUNCTIONS */
        // To avoid specifying return types and parameters, the following functions must be defined inside
        // the child classes. You can define the functions in the child class in order for the server to fit
        // your needs, handling connections, requests and responses however you want.
        virtual void accepter() = 0;
        virtual void handler() = 0;
        virtual void responder() = 0;

    public:
        /* CONSTRUCTOR */
        swServer(int domain, int service, int protocol, int port, u_long iface, int bklg);

        /* VIRTUAL FUNCTIONS */
        // The launch function will have to call the virtual member functions defined inside the child class.
        virtual void launch() = 0;

        /* GETTER FUNCTIONS */
        swListening_Socket* get_socket();
    };
}

#endif //SIMPLEWEB_SWSERVER_H
