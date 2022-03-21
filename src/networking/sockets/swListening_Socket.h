//
// Created by joaoa on 20/03/2022.
//

#ifndef SIMPLEWEB_SWLISTENING_SOCKET_H
#define SIMPLEWEB_SWLISTENING_SOCKET_H

#include "swSocket_Binder.h"

namespace swlib
{
    class swListening_Socket: public swSocket_Binder {
    private:
        int backlog;
        int listening;

    public:
        // Constructor
        swListening_Socket(int domain, int service, int protocol, int port, u_long iface, int bklg);

        void start_listening();

        /* GETTERS */
        int get_backlog() const;
        int get_listening() const;
    };
}

#endif //SIMPLEWEB_SWLISTENING_SOCKET_H
