//
// Created by pogam-_g on 4/11/16.
//

#include <string>
#include "PhoneNumber.hpp"

Plazza::PhoneNumber::~PhoneNumber()
{

}

std::string Plazza::PhoneNumber::getRegex() const
{
  return this->_regex;
}

Plazza::IOrder Plazza::PhoneNumber::create()
{
  return Plazza::PhoneNumber();
}


