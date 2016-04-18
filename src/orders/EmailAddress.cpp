//
// Created by pogam-_g on 4/11/16.
//

#include "EmailAddress.hpp"

Plazza::EmailAddress::~EmailAddress()
{

}

std::string Plazza::EmailAddress::getRegex() const
{
  return this->_regex;
}

Plazza::IOrder Plazza::EmailAddress::create()
{
  return Plazza::EmailAddress();
}
