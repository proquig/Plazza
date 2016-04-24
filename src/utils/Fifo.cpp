//
// Created by cloquet on 14/04/16.
//

#include <sstream>
#include "Fifo.hpp"

Plazza::Fifo::Fifo(const std::string &name)
	: _name(name),
	  _path("/tmp/")
{
  this->_path += name;

  mkfifo(this->_path.c_str(), 0666);
}

Plazza::Fifo::~Fifo()
{
  _out.close();
  _in.close();
  unlink(this->_path.c_str());
}

void 		Plazza::Fifo::write(const std::string &message)
{
  if (!this->_out.is_open())
    this->_out.open(this->_path.c_str(), std::ofstream::out);
  this->_out << message << std::endl;
}

std::string	Plazza::Fifo::read()
{
  std::string message;

  if (!this->_in.is_open())
    this->_in.open(this->_path.c_str(), std::ifstream::in);
  std::getline(this->_in, message);
  return message;
}
