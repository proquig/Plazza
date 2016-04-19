//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_PHONENUMBER_H
#define CPP_PLAZZA_PHONENUMBER_H

#include <fstream>
#include "AOrder.hpp"

namespace Plazza
{
  class PhoneNumber : public AOrder
  {
    const std::string _order = "PHONE_NUMBER";
    const std::string _regex = "(0|\\+33|0033)[1-9][0-9]{8}";

   public:
    virtual ~PhoneNumber();

    virtual const std::string &getOrder() const override;

    virtual const std::string &getRegex() const override;

    virtual IOrder *clone() const override;
  };
}

#endif //CPP_PLAZZA_PHONENUMBER_H
