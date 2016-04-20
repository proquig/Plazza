//
// Created by cloquet on 20/04/16.
//

#ifndef CPP_PLAZZA_CLIENT_HPP
#define CPP_PLAZZA_CLIENT_HPP

#include "Exception.hpp"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>

#define PORT 8080

//template <typename T>
class Client
{
 private:
  int _socket;
  struct sockaddr_in _addr_in;

 public:
  Client();
  ~Client();
  void Send(const std::string &);
  void Receive(const std::string &);
};


#endif //CPP_PLAZZA_CLIENT_HPP
