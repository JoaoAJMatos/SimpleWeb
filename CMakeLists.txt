cmake_minimum_required(VERSION 3.21)
project(SimpleWeb)

set(CMAKE_CXX_STANDARD 14)
link_libraries(ws2_32 wsock32)

add_executable(SimpleWeb main.cpp src/swlib.h src/networking/sockets/swSocket.cpp src/networking/sockets/swSocket.h src/networking/sockets/swSocket_Binder.cpp src/networking/sockets/swSocket_Binder.h src/networking/sockets/swConnecting_Socket.cpp src/networking/sockets/swConnecting_Socket.h src/networking/sockets/swListening_Socket.cpp src/networking/sockets/swListening_Socket.h src/networking/sockets/swlib_sockets.h src/networking/swlib_networking.h src/networking/server/swServer.cpp src/networking/server/swServer.h src/networking/server/exs/swServer_test.cpp src/networking/server/exs/swServer_test.h)
