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

  Socket(const int &);

  void initSocket(int max_socket);

  ~Socket();

  std::string getMsg() const;
};

#endif //CPP_PLAZZA_SOCKET_HPP
