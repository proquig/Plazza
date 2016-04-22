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
: log("Server.log")
{
  initSocket(max_socket);
}

void Socket::initSocket(int max_socket)
{
  int recsize = sizeof _addr_in;
  int sock_err = 1;
  this->_socket = socket(AF_INET, SOCK_STREAM, 0);
  if(this->_socket != INVALID_SOCKET)
    {
      log  << "La socket "<< this->_socket << "est maintenant ouverte en mode TCP/IP\n";
      _addr_in.sin_addr.s_addr = htonl(INADDR_ANY);
      _addr_in.sin_family = AF_INET;
      _addr_in.sin_port = htons(PORT);
      if (bind(this->_socket, (sockaddr*) &_addr_in, (socklen_t)recsize) != SOCKET_ERROR)
	{
	  sock_err = listen(this->_socket, max_socket);
	  log << "Listage du port " << PORT << "..." << std::endl;
	  if(sock_err != SOCKET_ERROR)
	    {
	      fd_set readfs;
	      while(1)
		{
		  FD_ZERO(&readfs);
		  FD_SET(this->_socket, &readfs);
		  if (select(this->_socket + 1, &readfs, NULL, NULL, NULL) < 0)
		    {
		      perror("select()");
		      throw (exception("Error in Select."));
		    }
		  if (FD_ISSET(this->_socket, &readfs))
		    {
		      struct sockaddr_in csin;
		      int crecsize = sizeof csin;
		      std::string buffer("");

		      SOCKET csock = accept(this->_socket, (sockaddr *) &csin, (socklen_t *) &crecsize);
		      if (recv(csock, (void*)buffer.c_str(), 32, 0) == -1)
			throw (exception("Can't Receive message"));
		      std::cout << "Le serveur à recus : ["<< buffer.c_str() << "]" << std::endl;
		      this->_msg = buffer.c_str();
		      closesocket(csock);
		      log << "Un client s'est connecte" << std::endl;
		    }
		}
	    }
	}
    }
}

std::string Socket::getMsg() const
{
  return _msg;
}

Socket::~Socket()
{
}
