cmake_minimum_required(VERSION 3.21)
project(SimpleWeb)

set(CMAKE_CXX_STANDARD 14)
link_libraries(ws2_32 wsock32)

add_executable(SimpleWeb main.cpp src/swlib.cpp src/swlib.h src/networking/swSocket.cpp src/networking/swSocket.h src/networking/swSocket_Binder.cpp src/networking/swSocket_Binder.h src/networking/swConnecting_Socket.cpp src/networking/swConnecting_Socket.h)
