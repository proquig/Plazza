//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_EMAILADDRESS_H
#define CPP_PLAZZA_EMAILADDRESS_H

#include "AOrder.hpp"

namespace Plazza
{
  class EmailAddress : public AOrder
  {
    const std::string _order = "EMAIL_ADDRESS";
    const std::string _regex = "";

   public:
    virtual ~EmailAddress() override;

    virtual const std::string &getOrder() const override;

    virtual const std::string &getRegex() const override;

    virtual IOrder *clone() const override;
  };
}

#endif //CPP_PLAZZA_EMAILADDRESS_H
