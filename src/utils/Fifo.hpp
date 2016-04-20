//
// Created by cloquet on 14/04/16.
//

#ifndef CPP_PLAZZA_FIFO_HPP
#define CPP_PLAZZA_FIFO_HPP


#include <string>
#include <fstream>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "Exception.hpp"

namespace Plazza
{
  class Fifo
  {
   private:
    std::string _name;
    std::string _path;
    std::ifstream _in;
    std::ofstream _out;

   public:
    Fifo(const std::string &);

    ~Fifo();

    std::ifstream &writeIn();

    std::ofstream &readIn();
  };
}


#endif //CPP_PLAZZA_FIFO_HPP
