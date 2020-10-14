//
// Created by Alex Korzh on 14.10.2020.
//

#include "UnixSocket.h"

#pragma once

namespace Sockets {
class SocketConnection;

class ServerUnixSocket : public UnixSocket
{
public:
    explicit ServerUnixSocket(const std::string& name);
    ~ServerUnixSocket() noexcept override;
    ServerUnixSocket(const ServerUnixSocket&) = delete;
    ServerUnixSocket(ServerUnixSocket&& from) noexcept;
    ServerUnixSocket& operator= (const ServerUnixSocket&) = delete;
    ServerUnixSocket& operator= (ServerUnixSocket&& from) noexcept;

    std::string getName() const;

    SocketConnection accept();

private:
    size_t _maxPendings = 10;
};

} // namespace Sockets