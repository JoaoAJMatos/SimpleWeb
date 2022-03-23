//
// Created by joaoa on 22/03/2022.
//

#include "swServer_test.h"

/* CONSTRUCTOR */
swlib::swServer_test::swServer_test(): swServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10)
{
    launch();
}

/* VIRTUAL FUNCTIONS */
void swlib::swServer_test::accepter()
{
    struct sockaddr_in address = get_socket()->get_address();
    int addrlen = sizeof(address);
    new_socket = accept(get_socket()->get_sock(), (struct sockaddr *)&address, (socklen_t *)&addrlen);

    // Check if an error occurs
    if (new_socket == INVALID_SOCKET)
    {
        perror("In accept");
        exit(EXIT_FAILURE);
    }

    recv(new_socket, buffer, 30000, 0);
}

void swlib::swServer_test::handler() {
    std::cout << buffer << std::endl;
}

void swlib::swServer_test::responder() {
    char *hello = "Hello from server";
    write(new_socket, hello, strlen(hello));
    close(new_socket);
}

/* PUBLIC FUNCTIONS */
[[noreturn]] void swlib::swServer_test::launch() {
    while (true)
    {
        std::cout << "==== WAITING ====" << std::endl;
        accepter();
        handler();
        responder();
        std::cout << "=== DONE ====" << std::endl;
    }
}


