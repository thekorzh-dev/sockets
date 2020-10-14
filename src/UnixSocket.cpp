//
// Created by Alex Korzh on 14.10.2020.
//

#include "UnixSocket.h"
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>

namespace Sockets {

UnixSocket::UnixSocket(const std::string& name)
  : _name(name)
{
  _id = socket(AF_UNIX, SOCK_STREAM, 0);
  if (_id == -1) {
    throw std::runtime_error("Error creating socket");
  }
  std::clog << "Unix socket created" << std::endl;

  _address.sun_family = AF_UNIX;
  strcpy(_address.sun_path, _name.c_str());
}

UnixSocket::~UnixSocket() noexcept
{
  if (_id != BadDescriptor) {
    close(_id);
  }
}

UnixSocket::UnixSocket(UnixSocket&& from) noexcept
        : _id(std::exchange(from._id, BadDescriptor))
        , _name(std::exchange(from._name, ""))
{
  memcpy(&_address, &from._address, sizeof(sockaddr_un));
}

UnixSocket& UnixSocket::operator=(UnixSocket&& from) noexcept
{
  std::swap(_id, from._id);
  std::swap(_name, from._name);
  memcpy(&_address, &from._address, sizeof(sockaddr_un));
  return *this;
}

} // namespace Sockets