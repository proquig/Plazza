//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_IORDER_H
#define CPP_PLAZZA_IORDER_H

#include <string>

namespace Plazza
{
  class IOrder
  {
   public:
    virtual ~IOrder()
    { }

    virtual const std::string & getRegex() const = 0;

    virtual const std::string &getFile() const = 0;

    virtual void setFile(const std::string &file) = 0;

    virtual IOrder *clone() const = 0;
  };
}

#endif //CPP_PLAZZA_IORDER_H
