//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_IPADDRESS_H
#define CPP_PLAZZA_IPADDRESS_H

#include <string>
#include "AOrder.hpp"

namespace Plazza
{
  class IpAddress : public AOrder
  {
    const std::string _order = "IP_ADDRESS";
    const std::string _regex = "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." \
      "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." \
      "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." \
      "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)";

   public:
    virtual ~IpAddress() override;

    virtual const std::string &getOrder() const override;

    virtual const std::string &getRegex() const override;

    virtual IOrder *clone() const override;
  };
}

#endif //CPP_PLAZZA_IPADDRESS_H
