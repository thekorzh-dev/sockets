//
// Created by Alex Korzh on 14.10.2020.
//

#include "ServerUnixSocket.h"
#include "SocketConnection.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

namespace Sockets {
ServerUnixSocket::ServerUnixSocket(const std::string& name)
        : UnixSocket(name)
{
  unlink(_name.c_str());

  sockaddr_un address;
  address.sun_family = AF_UNIX;
  strcpy(address.sun_path, _name.c_str());
  if (bind(_id, reinterpret_cast<sockaddr*>(&address), sizeof(sockaddr_un))) {
    throw std::runtime_error("Error binding socket");
  }
  std::clog << "Address successfully bound" << std::endl;
  listen(_id, _maxPendings);
}

ServerUnixSocket::~ServerUnixSocket() noexcept
{
  unlink(_name.c_str());
  std::clog << "Socket file is unlinked" << std::endl;
}

ServerUnixSocket::ServerUnixSocket(ServerUnixSocket&& from) noexcept
  : UnixSocket(std::move(from))
{
}

ServerUnixSocket& ServerUnixSocket::operator = (ServerUnixSocket&& from) noexcept
{
  UnixSocket::operator=(std::move(from));
  return *this;
}

std::string ServerUnixSocket::getName() const
{
  return _name;
}

SocketConnection ServerUnixSocket::accept()
{
  std::clog << "Accepting..." << std::endl;
  const auto stream = ::accept(_id, 0, 0);
  if (stream == -1) {
    throw std::runtime_error("Error accepting connection");
  }
  std::clog << "Client connected" << std::endl;
  return SocketConnection(stream);
}

} // namespace Sockets