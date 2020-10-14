//
// Created by Alex Korzh on 14.10.2020.
//

#pragma once

#include "common.h"
#include <sys/un.h>

namespace Sockets {
class UnixSocket {
public:
    explicit UnixSocket(const std::string &name);
    virtual ~UnixSocket() noexcept;
    UnixSocket(const UnixSocket &) = delete;
    UnixSocket(UnixSocket &&from) noexcept;
    UnixSocket &operator= (const UnixSocket &) = delete;
    UnixSocket &operator= (UnixSocket &&) noexcept;

protected:
    int _id;
    std::string _name;
    sockaddr_un _address;
};

} // namespace Sockets