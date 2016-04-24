//
// Created by pogam-_g on 14/04/16.
//

#ifndef CPP_PLAZZA_ICONNECTOR_HPP
#define CPP_PLAZZA_ICONNECTOR_HPP

#include <string>

namespace Plazza
{
  class IConnector
  {
   public:
    virtual ~IConnector()
    { }

    virtual void write(const std::string &) = 0;

    virtual std::string read() = 0;

    virtual const std::string &getPath() const = 0;
  };
}

#endif //CPP_PLAZZA_ICONNECTOR_HPP
