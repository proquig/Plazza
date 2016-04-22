//
// Created by pogam-_g on 22/04/16.
//

#include <iostream>
#include "Process.hpp"

Plazza::Process::Process(size_t maxThreads) : _maxThreads(maxThreads), _lastAction(clock())
{
  this->_fork = new Fork();
  if (this->_fork->isChild())
    {

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

void Plazza::Process::sendOrder(IOrder *order)
{
  std::cout << *order << std::endl;
}

void Plazza::Process::updateClock()
{
  this->_lastAction = clock();
}
