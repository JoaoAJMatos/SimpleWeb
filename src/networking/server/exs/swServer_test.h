//
// Created by joaoa on 22/03/2022.
//

#ifndef SIMPLEWEB_SWSERVER_TEST_H
#define SIMPLEWEB_SWSERVER_TEST_H

#include "../swServer.h"
#include <unistd.h>

namespace swlib
{
    class swServer_test: public swServer {
    private:
        char buffer[30000];
        int new_socket;

        /* VIRTUAL MEMBER FUNCTIONS */
        // Virtual functions from parent (swServer.h)
        void accepter() override;
        void handler() override;
        void responder() override;

    public:
        swServer_test();

        /* VIRTUAL PUBLIC FUNCTIONS */
        // Virtual launch from parent
        [[noreturn]] void launch() override;
    };

}


#endif //SIMPLEWEB_SWSERVER_TEST_H
