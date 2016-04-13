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

    virtual void execute() = 0;

    virtual std::string getRegex() const = 0;
  };
}


#endif //CPP_PLAZZA_IORDER_H
