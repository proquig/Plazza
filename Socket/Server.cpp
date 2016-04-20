//
// Created by cloquet on 20/04/16.
//

#include "Server.hpp"
#include <errno.h>
#include <stdio.h>

Socket::Socket()
{
  initSocket(5);
}

Socket::Socket(const int &max_socket)
{
  initSocket(max_socket);
}

void Socket::initSocket(int max_socket)
{
  struct sockaddr_in csin;
  int fd;

  _socket = socket(AF_INET, SOCK_STREAM, 0);
  _addr_in.sin_addr.s_addr = htonl(INADDR_ANY);
  _addr_in.sin_family = AF_INET;
  _addr_in.sin_port = htons(PORT);

  if (bind(this->_socket, (sockaddr *) &_addr_in, sizeof(_addr_in)) == -1)
    {
      perror("bind");
      throw (exception("Server Can't be bind :\n\tError in Server.cpp line 13"));
    }
  if (listen(this->_socket, max_socket) == -1)
    throw (exception("Server Can't listen:\n\tError in Server.cpp line 15"));

  socklen_t taille = sizeof(csin);
  if ((fd = accept(_socket, (sockaddr *) &csin, &taille)))
    throw (exception("Server Can't accept:\n\tError in Server.cpp line 21"));

  char buffer[32] = "Bonjour !";
  if (send(fd, buffer, sizeof(buffer), 0) == -1)
    throw (exception("Server can't send msg:\n\tError in Server.cpp line 21"));
  shutdown(fd, 2);
}

Socket::~Socket()
{
}
