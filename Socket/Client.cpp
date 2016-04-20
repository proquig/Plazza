//
// Created by cloquet on 20/04/16.
//

#include "Client.hpp"

#include "stdio.h"

Client::Client()
{
  _socket = socket(AF_INET, SOCK_STREAM, 0);
  _addr_in.sin_addr.s_addr = inet_addr("0.0.0.0");
  _addr_in.sin_family = AF_INET;
  _addr_in.sin_port = htons(PORT);

  if(connect(_socket, (sockaddr*)&_addr_in, sizeof(_addr_in)) != -1)
    printf("Connexion à %s sur le port %d\n", inet_ntoa(_addr_in.sin_addr), htons(_addr_in.sin_port));
  else
    printf("Impossible de se connecter\n");
}

void Client::Send(const std::string &buffer)
{
  if (send(this->_socket, "toto", sizeof("toto"), 0) == -1)
    throw (exception("Can't Send message"));
}

void Client::Receive(const std::string &buffer)
{

  if (recv(this->_socket, (void*)buffer.c_str(), sizeof(buffer.c_str()), 0) == -1)
    throw (exception("Can't Receive message"));
}

Client::~Client()
{

}