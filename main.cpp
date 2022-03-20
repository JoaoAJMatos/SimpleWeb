#include <iostream>
#include "src/swlib.h"


int main() {

    std::cout << "Listening socket..." << std::endl;
    swlib::swListening_Socket ls = swlib::swListening_Socket(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10);
    std::cout << "Success!" << std::endl;

    return 0;
}
