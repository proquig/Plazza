//
// Created by cloquet on 14/04/16.
//

#include "Fifo.hpp"

Fifo::Fifo(const std::string &name)
	: _name(name),
	  _path("/tmp/")
{
  this->_path += name;
  if (mkfifo(this->_path.c_str(), 0666) == -1)
    std::cerr << "file [" << this->_path << "] Exist\n";
  else
    std::cerr << "file [" << this->_path << "] Created\n";
  try
    {
      this->_out.open(this->_path.c_str(), std::ofstream::out);
      std::cout << "file [" << this->_path << "] Created\n";
      this->_in.open(this->_path.c_str(), std::ifstream::in);
    } catch (std::exception &e)
    {
      std::cerr << e.what() << std::endl;
    }

}

std::ifstream 	&Fifo::writeIn()
{
  return (this->_in);
}

std::ofstream	&Fifo::readIn()
{
  return (this->_out);
}

Fifo::~Fifo()
{
  std::cerr << "fifo detruit" << std::endl;
  _out.close();
  _in.close();
  unlink(this->_path.c_str());
}