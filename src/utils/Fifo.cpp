//
// Created by cloquet on 14/04/16.
//

#include <fstream>
#include "Fifo.hpp"

Fifo::Fifo(const std::string &name)
	: _name(name),
	  _path("/tmp/")
{
  _path += name;
  if (mkfifo(_path.c_str(), 0666) == -1)
    throw(exception("Fifo can't be create."));
}

void Fifo::writeIn(const std::string &data)
{
  int fd;

  if ((fd = open(_path.c_str(), O_WRONLY)) == -1)
  	throw (exception("Cann't open the file"));
  write(fd, data.c_str(), sizeof(data.c_str()));
  close(fd);
}

std::string 	&Fifo::readIn()
{
  std::ifstream fifo(_path.c_str());
  std::string str;
  std::string res;
  bool done = false;

  while (!done)
    {
      while(std::getline(fifo, str))
	  res += str;
      if (fifo.eof())
	fifo.clear();
      else
	done = true;
    }
  return res;
}

Fifo::~Fifo()
{
  unlink(_path.c_str());
}