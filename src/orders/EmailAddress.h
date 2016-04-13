//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_EMAILADDRESS_H
#define CPP_PLAZZA_EMAILADDRESS_H

#include "../IOrder.h"

namespace Plazza
{
  class EmailAddress : public IOrder
  {
    const std::string _regex = "";

   public:
    virtual ~EmailAddress() override;

    virtual std::string getRegex() const override
    {
      return this->_regex;
    }
  };
}


#endif //CPP_PLAZZA_EMAILADDRESS_H
