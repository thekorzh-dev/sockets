cmake_minimum_required(VERSION 3.15)
project(Sockets
        LANGUAGES CXX
        DESCRIPTION "Sockets library")

set(CMAKE_CXX_STANDARD 17)

add_library(sockets
        include/ServerUnixSocket.h
        include/ClientUnixSocket.h
        include/SocketConnection.h
        include/common.h
        include/UnixSocket.h
        src/UnixSocket.cpp
        src/ServerUnixSocket.cpp src/ClientUnixSocket.cpp src/SocketConnection.cpp)
target_include_directories(sockets PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(server server.cpp)
target_link_libraries(server sockets)

add_executable(client client.cpp)
target_link_libraries(client sockets)