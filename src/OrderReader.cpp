//
// Created by pogam-_g on 4/11/16.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "OrderReader.hpp"
#include "orders/EmailAddress.hpp"
#include "orders/PhoneNumber.hpp"

Plazza::OrderReader::OrderReader()
{
  this->_factory.registerType("EMAIL_ADDRESS", new EmailAddress);
  this->_factory.registerType("IP_ADDRESS", new EmailAddress);
  this->_factory.registerType("PHONE_NUMBER", new PhoneNumber);
}

void				Plazza::OrderReader::parseCommand(const std::string &command)
{
  std::stringstream		commandStream(command);
  std::vector<std::string>	files;
  std::string			orderType;
  std::string			word;

  while (std::getline(commandStream, word, ' '))
    if (word.length())
      files.push_back(word);
  orderType = files.back();
  files.pop_back();

  for (std::vector<std::string>::iterator it = files.begin(); it != files.end(); it++)
    {
      this->_orders.push(this->_factory.create(orderType));
      this->_orders.back()->setFile(*it);
    }
}

void Plazza::OrderReader::parseLine(const std::string &line)
{
  std::stringstream               lineStream(line);
  std::string                     command;

  while (std::getline(lineStream, command, ';'))
    if (command.length())
      parseCommand(command);
}

const std::queue<IOrder *> &Plazza::OrderReader::get_orders() const
{
  return this->_orders;
}