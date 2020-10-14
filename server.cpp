
#include "common.h"
#include "include/ServerUnixSocket.h"
#include "include/SocketConnection.h"
#include <thread>

void serverLoop(Sockets::ServerUnixSocket& socket)
{
  while (1) {
    socket.accept().send("Hello from server");
  }
}

int main()
{
  Sockets::ServerUnixSocket socket(SocketName);
  std::thread loop(serverLoop, std::ref(socket));
  loop.join();

  return EXIT_SUCCESS;
}
