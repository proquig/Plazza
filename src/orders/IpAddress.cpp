//
// Created by pogam-_g on 4/11/16.
//

#include "IpAddress.h"

Plazza::IpAddress::~IpAddress()
{

}

std::string Plazza::IpAddress::getRegex() const
{
  return this->_regex;
}
