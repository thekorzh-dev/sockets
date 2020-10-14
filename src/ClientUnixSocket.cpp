//
// Created by Alex Korzh on 14.10.2020.
//

#include "common.h"
#include "ClientUnixSocket.h"
#include "SocketConnection.h"

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

namespace Sockets {
ClientUnixSocket::ClientUnixSocket(const std::string &name)
        : UnixSocket(name)
{
  if (connect(_id, reinterpret_cast<sockaddr *>(&_address), sizeof(sockaddr_un))) {
    throw std::runtime_error("Error connecting server");
  }
  std::clog << "Connected to server" << std::endl;
}


ClientUnixSocket::ClientUnixSocket(ClientUnixSocket &&from) noexcept
  : UnixSocket(std::move(from))
{
}

ClientUnixSocket& ClientUnixSocket::operator=(ClientUnixSocket &&from) noexcept
{
  UnixSocket::operator=(std::move(from));
  return *this;
}

SocketConnection& ClientUnixSocket::getConnection() const {
  static SocketConnection connection(_id);
  return connection;
}

} // namespace Sockets