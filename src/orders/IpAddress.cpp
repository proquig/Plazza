//
// Created by pogam-_g on 4/11/16.
//

#include "IpAddress.hpp"

Plazza::IpAddress::~IpAddress()
{
}

const std::string &Plazza::IpAddress::getRegex() const
{
  return this->_regex;
}

Plazza::IOrder *Plazza::IpAddress::clone() const
{
  return new IpAddress(*this);
}
