//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_IPADDRESS_H
#define CPP_PLAZZA_IPADDRESS_H

#include <string>
#include "../IOrder.h"

namespace Plazza
{
  class IpAddress : public IOrder
  {
    const std::string _regex = "^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?).(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)." \
          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?).(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$";

   public:
    virtual ~IpAddress() override;

    virtual std::string getRegex() const override;
  };
}


#endif //CPP_PLAZZA_IPADDRESS_H
