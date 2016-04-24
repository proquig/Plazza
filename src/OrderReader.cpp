//
// Created by pogam-_g on 4/11/16.
//

#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unistd.h>
#include "OrderReader.hpp"
#include "orders/EmailAddress.hpp"
#include "orders/IpAddress.hpp"
#include "orders/PhoneNumber.hpp"

Plazza::OrderReader::OrderReader(ISafeQueue<IOrder *> *ordersQueue) : _orders(ordersQueue), _mainPid(getpid())
{
  this->_factory.registerType("EMAIL_ADDRESS", new EmailAddress);
  this->_factory.registerType("IP_ADDRESS", new IpAddress);
  this->_factory.registerType("PHONE_NUMBER", new PhoneNumber);
}

Plazza::OrderReader::~OrderReader()
{
  this->_thread->join();
}

void Plazza::OrderReader::start()
{
  this->_thread = new std::thread(&OrderReader::reader, this);
}

void                                Plazza::OrderReader::reader()
{
  std::string line;

  while (this->_mainPid == getpid() && std::getline(std::cin, line))
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
	  this->notify();
	}
      else
	std::cerr << "Error: Invalid order " << orderType << std::endl;
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

void Plazza::OrderReader::addObserver(IObserver *obs)
{
  this->_observers.push_back(obs);
}

void Plazza::OrderReader::deleteObserver(IObserver *obs)
{
  const std::list<IObserver *>::iterator &it = std::find(this->_observers.begin(), this->_observers.end(), obs);
  if (it != this->_observers.end())
    this->_observers.erase(it);
}

void Plazza::OrderReader::notify(void)
{
  for (std::list<IObserver *>::iterator it = this->_observers.begin(); it != this->_observers.end(); it++)
    {
      (*it)->update();
      usleep(100);
    }
}
