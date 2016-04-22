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

#include "stdio.h"

#define PORT 8080

class Client
{
 private:
  int _socket;
  struct sockaddr_in _addr_in;

 public:
  Client();
  ~Client();
  template <class F>
  void Send(const F &);
  std::string &Receive();
};

Client::Client()
{
  _socket = socket(AF_INET, SOCK_STREAM, 0);
  _addr_in.sin_addr.s_addr = htonl(INADDR_ANY);
  _addr_in.sin_family = AF_INET;
  _addr_in.sin_port = htons(PORT);

  if (connect(_socket, (sockaddr*)&_addr_in, sizeof(_addr_in)) == -1)
    throw (exception("Impossible de se connecter"));
}

template <class F>
void Client::Send(const F &buffer)
{
  if (send(this->_socket, &buffer, sizeof(buffer), 0) == -1)
    throw (exception("Can't Send message"));
}

std::string &Client::Receive()
{
  std::string buffer("");
  if (recv(this->_socket, (void*)buffer.c_str(), 32, 0) == -1)
    throw (exception("Can't Receive message"));
  return buffer;
}

Client::~Client()
{

}


#endif //CPP_PLAZZA_CLIENT_HPP
