//
// Created by pogam-_g on 22/04/16.
//

#include <iostream>
#include <sstream>
#include "Process.hpp"
#include "../utils/Factory.hpp"
#include "../utils/Parser.hpp"
#include "../utils/Decrypt.hpp"
#include "ThreadPool.hpp"

Plazza::Process::Process(size_t maxThreads, std::string message)
	: _lastAction(std::time(nullptr)), _pool(nullptr), _ordersRunning(0)
{
  this->_fork = new Fork();
  if (this->_fork->isChild())
    {
      this->_pool = new ThreadPool(maxThreads, &parseFile);
      this->_pool->addObserver(this);
      parseMessage(message);
      this->_timeTracker = new std::thread(&Process::timeTracker, this);
    }
}

Plazza::Process::~Process()
{
  if (this->_pool != nullptr)
    delete this->_pool;
  delete this->_fork;
}

bool Plazza::Process::canAcceptOrder()
{
  return false;
}

void Plazza::Process::sendOrder(const IOrder &order)
{
  (void)order;
}

void Plazza::Process::stop()
{
  this->_pool->stop();
  delete (this);
}

void Plazza::Process::update()
{
  this->_ordersRunning--;
  if (this->_ordersRunning == 0)
    this->_lastAction = std::time(nullptr);
}

void Plazza::Process::timeTracker()
{
  for (;;)
    {
      if (this->_ordersRunning == 0)
	{
	  if (std::time(nullptr) - this->_lastAction >= 2)
	    {
	      this->stop();
	      return;
	    }
	}
      usleep(100);
    }
}

void Plazza::Process::parseMessage(const std::string message)
{
  std::stringstream stream(message);
  std::string command;
  std::string file;
  IOrder *order;

  std::getline(stream, command, ' ');
  if (command == "canAcceptOrder")
    { }
  else
    {
      std::getline(stream, file, ' ');
      order = deserialize(command, file);
      this->_ordersRunning++;
      this->_pool->enqueue(*order);
    }
}

Plazza::IOrder *Plazza::Process::deserialize(const std::string &type, const std::string &file)
{
  Factory<IOrder> factory;
  IOrder *order;

  order = factory.create(type);
  order->setFile(file);
  return order;
}

void Plazza::Process::parseFile(const IOrder &order)
{
  try
    {
      Decrypt decrypt(order);
      std::vector<std::string> strings;

      strings = decrypt.decrypt();
      for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
	std::cout << *it << std::endl;
    }
  catch (std::exception &e)
    {
      std::cerr << e.what() << std::endl;
    }
}


