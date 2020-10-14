//
// Created by Alex Korzh on 11.10.2020.
//

#include "common.h"
#include "include/SocketConnection.h"
#include "include/ClientUnixSocket.h"

#include <iostream>

int main ()
{
  Sockets::ClientUnixSocket socket(SocketName);
  socket.getConnection().receive([](const std::string& message) {
    std::cout << message << std::endl;
  });

  return EXIT_SUCCESS;
}