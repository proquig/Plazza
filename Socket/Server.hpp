//
// Created by cloquet on 20/04/16.
//

#ifndef CPP_PLAZZA_SOCKET_HPP
#define CPP_PLAZZA_SOCKET_HPP

#include "Exception.hpp"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>

#define PORT 8080

class Socket
{
 private:
  int _socket;
  struct sockaddr_in _addr_in;

 public:
  Socket();
  Socket(const size_t &);
  ~Socket();
};


#endif //CPP_PLAZZA_SOCKET_HPP
