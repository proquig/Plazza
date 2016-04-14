//
// Created by cloquet on 14/04/16.
//

#ifndef CPP_PLAZZA_FIFO_HPP
#define CPP_PLAZZA_FIFO_HPP


#include <string>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "Exception.hpp"

class Fifo
{
 private:
	std::string _name;
	std::string _path;
  	Fifo(){};
 public:
  	Fifo(const std::string &);
  	~Fifo();
  	void writeIn(const std::string &);
  	std::string & readIn();

};


#endif //CPP_PLAZZA_FIFO_HPP
