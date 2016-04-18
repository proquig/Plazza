//
// Created by pogam-_g on 4/18/16.
//

#include "OrderFactory.hpp"
#include "IpAddress.hpp"
#include "EmailAddress.hpp"
#include "PhoneNumber.hpp"

Plazza::OrderFactory::OrderFactory()
{
  this->orderClass.insert(std::pair<ORDER_TYPE>("EMAIL_ADDRESS", &EmailAddress::create));
  this->orderClass.insert(std::pair<ORDER_TYPE>("IP_ADDRESS", &IpAddress::create));
  this->orderClass.insert(std::pair<ORDER_TYPE>("PHONE_NUMBER", &PhoneNumber::create));
}

Plazza::IOrder *Plazza::OrderFactory::createOrder(const std::string &type)
{
  return nullptr; //(this->orderClass.at(type))();
}
