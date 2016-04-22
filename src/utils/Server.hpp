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
#include <fstream>
#include <errno.h>

#define PORT 8080
#define closesocket(s) close (s)
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

typedef int SOCKET;

class Socket
{
 private:
  int _socket;
  struct sockaddr_in _addr_in;
  std::ofstream log;
  std::string _msg;

 public:
  Socket();

  Socket(const int &, const uint16_t &);

  void initSocket(int max_socket, uint16_t);

  ~Socket();

  std::string getMsg() const;

  template <typename F>
  void Send(const F &, int);
};

Socket::Socket()
{
  initSocket(5, 8080);
}

Socket::Socket(const int &max_socket, const uint16_t &port)
	: log("Server.log")
{
  initSocket(max_socket, port);
}

void Socket::initSocket(int max_socket, uint16_t port)
{
  int recsize = sizeof _addr_in;
  int sock_err = 1;
  this->_socket = socket(AF_INET, SOCK_STREAM, 0);
  if(this->_socket != INVALID_SOCKET)
    {
      log  << "La socket "<< this->_socket << "est maintenant ouverte en mode TCP/IP\n";
      _addr_in.sin_addr.s_addr = htonl(INADDR_ANY);
      _addr_in.sin_family = AF_INET;
      _addr_in.sin_port = htons(port);
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

template <typename F>
void Socket::Send(const F &buffer, int socket)
{
  if (send(socket, &buffer, sizeof(&buffer), 0) == -1)
    throw (exception("Can't Send message"));
}


Socket::~Socket()
{
}

#endif //CPP_PLAZZA_SOCKET_HPP
