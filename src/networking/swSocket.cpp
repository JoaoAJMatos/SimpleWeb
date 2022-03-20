//
// Created by joaoa on 20/03/2022.
//

#include "swSocket.h"

swlib::swSocket::swSocket() {

}

int swlib::swSocket::swInit() {
    // Start windows socket API
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        std::cerr << "Winsock Failed" << std::endl;
        getchar();
        return 1;
    }

    std::cout << "Windows Socket API started" << std::endl;

    // Create the network socket
    s = socket(AF_INET, SOCK_STREAM, 0);
    // Check for errors
    if (s == SOCKET_ERROR)
    {
        std::cerr << "Socket Error: " << WSAGetLastError() << std::endl;
        getchar();
        return 1;
    }


    std::cout << "Socket Created" << std::endl;

    server.sin_family = AF_INET; // IPv4 address family
    server.sin_port = htons(80);
    InetPton(AF_INET, _T("0.0.0.0"), &server.sin_addr); // Define network address to run server on

    // Bind host address and port number
    iResult = bind(s, (struct sockaddr*) &server, sizeof(server));
    // Check for errors
    if (iResult == SOCKET_ERROR)
    {
        std::cout << "Bind error: " << WSAGetLastError() << std::endl;
        getchar();
        return 1;
    }

    std::cout << "Listening on: 0.0.0.0:80" << std::endl;
    iResult = listen(s, AF_INET);

    return 0;
}
