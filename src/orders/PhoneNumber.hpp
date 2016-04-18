//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_PHONENUMBER_H
#define CPP_PLAZZA_PHONENUMBER_H

#include <fstream>
#include "IOrder.hpp"

namespace Plazza
{
  class PhoneNumber : public IOrder
  {
    const std::string _regex = "(0|\\+33|0033)[1-9][0-9]{8}";

   public:
    virtual ~PhoneNumber();

    virtual std::string getRegex() const override;
  };
}

#endif //CPP_PLAZZA_PHONENUMBER_H
