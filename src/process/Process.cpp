//
// Created by pogam-_g on 22/04/16.
//

#include <iostream>
#include <sstream>
#include "Process.hpp"
#include "../utils/Factory.hpp"
#include "../utils/Parser.hpp"
#include "../utils/Decrypt.hpp"
#include "../utils/ThreadPool.hpp"

Plazza::Process::Process(size_t maxThreads) : _maxThreads(maxThreads), _lastAction(clock())
{
  this->_fork = new Fork();
  if (this->_fork->isChild())
    {
      //this->_pool = new ThreadPool(maxThreads);
    }
}

Plazza::Process::~Process()
{
}

bool Plazza::Process::canAcceptOrder()
{
  /*if (!this->_fork->isChild())
    {
       this->_writer->write("canAcceptOrder");
       std::string r = this->_reader->read();
       if (r == "true")
         return true;
    }*/
  return false;
}

void Plazza::Process::sendOrder(const IOrder &order)
{
  std::cout << order << std::endl;
}

void Plazza::Process::updateClock()
{
  this->_lastAction = clock();
}

void Plazza::Process::parseMessage(const std::string message)
{
  std::stringstream stream(message);
  std::string command;
  std::string file;
  IOrder *order;

  std::getline(stream, command, ' ');
  if (command == "canAcceptOrder")
    {}
  else
    {
      std::getline(stream, file, ' ');
      order = deserialize(command, file);
      /*_pool->enqueue([this] (IOrder *lorder){
	    Plazza::Process::parseFile(*lorder);
	  }, order);*/
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
  Decrypt decrypt(order);
  std::vector<std::string> strings;

  strings = decrypt.decrypt();
  for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
    std::cout << *it << std::endl;
}
