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
    virtual ~IConnector()
    { }

    virtual void writeIn(const std::string &) = 0;

    virtual std::string &readIn() = 0;

    virtual const std::string &getPath() const = 0;
  };
}

#endif //CPP_PLAZZA_ICONNECTOR_HPP
