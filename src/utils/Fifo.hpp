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
#include <IConnector.hpp>
#include "Exception.hpp"

namespace Plazza
{
  class Fifo : public IConnector
  {
   private:
    std::string _name;
    std::string _path;
    std::ifstream _in;
    std::ofstream _out;

   public:
    Fifo(const std::string &);

    ~Fifo();

    virtual void write(const std::string &message) override;

    virtual std::string read() override;

    virtual const std::string & getPath() const;
  };
}


#endif //CPP_PLAZZA_FIFO_HPP
