//
// Created by pogam-_g on 4/11/16.
//

#include <iostream>
#include <sstream>
#include "OrderReader.hpp"
#include "orders/EmailAddress.hpp"
#include "orders/IpAddress.hpp"
#include "orders/PhoneNumber.hpp"

Plazza::OrderReader::OrderReader(ISafeQueue<IOrder *> *ordersQueue) : _orders(ordersQueue), _stop(false)
{
  this->_factory.registerType("EMAIL_ADDRESS", new EmailAddress);
  this->_factory.registerType("IP_ADDRESS", new IpAddress);
  this->_factory.registerType("PHONE_NUMBER", new PhoneNumber);

  this->_thread = new std::thread(&OrderReader::reader, this);
}

Plazza::OrderReader::~OrderReader()
{
  this->_thread->join();
}

void Plazza::OrderReader::stop()
{
  this->_stop = true;
}

void                                Plazza::OrderReader::reader()
{
  std::string line;

  while (!this->_stop && std::getline(std::cin, line))
    parseLine(line);
}

void                                Plazza::OrderReader::parseCommand(const std::string &command)
{
  std::stringstream commandStream(command);
  std::vector<std::string> files;
  std::string orderType;
  std::string word;

  while (std::getline(commandStream, word, ' '))
    if (word.length())
      files.push_back(word);
  orderType = files.back();
  files.pop_back();

  for (std::vector<std::string>::iterator it = files.begin(); it != files.end(); it++)
    {
      IOrder *pOrder = this->_factory.create(orderType);
      if (pOrder != nullptr)
	{
	  pOrder->setFile(*it);
	  this->_orders->push(pOrder);
	}
    }
}

void                                Plazza::OrderReader::parseLine(const std::string &line)
{
  std::stringstream lineStream(line);
  std::string command;

  while (std::getline(lineStream, command, ';'))
    if (command.length())
      parseCommand(command);
}


