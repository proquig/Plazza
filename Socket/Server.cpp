//
// Created by cloquet on 20/04/16.
//

#include "Server.hpp"
#include <errno.h>
#include <stdio.h>

Socket::Socket(const size_t &max_socket)
{
  struct sockaddr_in csin;
  struct sockaddr csock;

  _socket = socket(AF_INET, SOCK_STREAM, 0);
  _addr_in.sin_addr.s_addr = htonl(INADDR_ANY);
  _addr_in.sin_family = AF_INET;
  _addr_in.sin_port = htons(PORT);

  if (bind(this->_socket, (sockaddr*)&_addr_in, sizeof(_addr_in)) == -1)
    {
      perror("bind");
      throw(exception("Server Can't be bind :\n\tError in Server.cpp line 13"));
    }
  if (listen(this->_socket, max_socket) == -1)
    throw (exception("Server Can't listen:\n\tError in Server.cpp line 15"));

  socklen_t taille = sizeof(csin);
  if ((csock = accept(_socket, (sockaddr*)&csin, &taille)))
    throw (exception("Server Can't accept:\n\tError in Server.cpp line 21"));

  char buffer[32] = "Bonjour !";
  if (send(csock, buffer, sizeof(buffer)) == -1)
    throw (exception("Server can't send msg:\n\tError in Server.cpp line 21"));
  shutdown(csock, 2);
}


Socket::Socket()
{
  _socket = socket(AF_INET, SOCK_STREAM, 0);
  _addr_in.sin_addr.s_addr = inet_addr("0.0.0.0");
  _addr_in.sin_family = AF_INET;
  _addr_in.sin_port = htonl(PORT);
  if (bind(this->_socket, (sockaddr*)&_addr_in, sizeof(_addr_in)))
    throw(exception("Server Can't be bind :\n\tError in Server.cpp line 13"));
  listen(this->_socket, 5);

}

Socket::~Socket()
{
}