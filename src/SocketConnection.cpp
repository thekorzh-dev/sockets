//
// Created by Alex Korzh on 14.10.2020.
//

#include <SocketConnection.h>

#include <unistd.h>
#include <sys/socket.h>

namespace Sockets {
SocketConnection::SocketConnection(int connectionId)
  : _connectionId(connectionId)
{
}

SocketConnection::~SocketConnection() noexcept
{
  close(_connectionId);
}

SocketConnection::SocketConnection(SocketConnection&& from) noexcept
  : _connectionId(std::exchange(from._connectionId, BadDescriptor))
{
}

SocketConnection& SocketConnection::operator = (SocketConnection&& from) noexcept
{
  std::swap(_connectionId, from._connectionId);
  return *this;
}

SocketConnection& SocketConnection::receive(ReceiveCallback&& callback)
{
  char buf[1024] = {};
  recv(_connectionId, buf, 1024, 0);
  callback(std::string(buf));
  return *this;
}

SocketConnection& SocketConnection::send(const std::string& message)
{
  ::send(_connectionId, message.c_str(), message.length(), 0);
  return *this;
}

} // namespace Sockets