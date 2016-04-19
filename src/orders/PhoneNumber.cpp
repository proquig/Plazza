//
// Created by pogam-_g on 4/11/16.
//

#include <string>
#include "PhoneNumber.hpp"

Plazza::PhoneNumber::~PhoneNumber()
{
}

const std::string &Plazza::PhoneNumber::getOrder() const
{
  return this->_order;
}

const std::string &Plazza::PhoneNumber::getRegex() const
{
  return this->_regex;
}

Plazza::IOrder *Plazza::PhoneNumber::clone() const
{
  return new PhoneNumber(*this);
}
