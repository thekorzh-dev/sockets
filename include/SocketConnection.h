//
// Created by Alex Korzh on 14.10.2020.
//

#include "common.h"

#pragma once

namespace Sockets {
class ServerUnixSocket;

class SocketConnection
{
  friend class ServerUnixSocket;
  friend class ClientUnixSocket;

public:
  virtual ~SocketConnection() noexcept;
  SocketConnection(const SocketConnection&) = delete;
  SocketConnection(SocketConnection&& from) noexcept;
  SocketConnection& operator= (const SocketConnection&) = delete;
  SocketConnection& operator= (SocketConnection&& from) noexcept;

  SocketConnection& receive(ReceiveCallback&& callback);
  SocketConnection& send(const std::string& message);

private:
  explicit SocketConnection(int connectionId);

private:
    int _connectionId;
};

} // namespace Sockets