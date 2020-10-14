//
// Created by Alex Korzh on 14.10.2020.
//

#pragma once

#include "UnixSocket.h"

namespace Sockets {
class SocketConnection;

class ClientUnixSocket : public UnixSocket
{
public:
    explicit ClientUnixSocket(const std::string& name);
    ClientUnixSocket (const ClientUnixSocket&) = delete;
    ClientUnixSocket (ClientUnixSocket&& from) noexcept;
    ClientUnixSocket& operator= (const ClientUnixSocket&) = delete;
    ClientUnixSocket& operator= (ClientUnixSocket&& from) noexcept;

    SocketConnection& getConnection() const;

};

} // namespace Sockets