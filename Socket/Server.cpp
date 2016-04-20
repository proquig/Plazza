//
// Created by cloquet on 20/04/16.
//

#include "Server.hpp"
#include <errno.h>
#include <stdio.h>

Socket::Socket(const size_t &max_socket)
{
  bool launch = true;
  struct sockaddr_in csin;
  struct sockaddr csock;

  _socket = socket(AF_INET, SOCK_STREAM, 0);
  _addr_in.sin_addr.s_addr = htonl(INADDR_ANY);
  _addr_in.sin_family = AF_INET;
  _addr_in.sin_port = htons(PORT);
  if (bind(this->_socket, (sockaddr*)&_addr_in, sizeof(_addr_in)) == -1)
    {
      perror("bind");
      throw(exception("Socket Can't be bind :\n\tError in Socket.cpp line 13"));
    }
  if (listen(this->_socket, max_socket) == -1)
    throw (exception("Socket Can't listen:\n\tError in Socket.cpp line 15"));
  socklen_t taille = sizeof(csin);
  if (accept(_socket, (sockaddr*)&csin, &taille) == false)
    throw (exception("Socket Can't accept:\n\tError in Socket.cpp line 21"));
  while (launch)
    {


    }
}


Socket::Socket()
{
  _socket = socket(AF_INET, SOCK_STREAM, 0);
  _addr_in.sin_addr.s_addr = inet_addr("0.0.0.0");
  _addr_in.sin_family = AF_INET;
  _addr_in.sin_port = htonl(PORT);
  if (bind(this->_socket, (sockaddr*)&_addr_in, sizeof(_addr_in)))
    throw(exception("Socket Can't be bind :\n\tError in Socket.cpp line 13"));
  listen(this->_socket, 5);

}

Socket::~Socket()
{
}