//
// Created by pogam-_g on 22/04/16.
//

#include "OrderDispatcher.hpp"

Plazza::OrderDispatcher::OrderDispatcher(size_t maxThreads) : _maxThreads(maxThreads)
{
}

Plazza::OrderDispatcher::~OrderDispatcher()
{
}

void Plazza::OrderDispatcher::dispatch(const IOrder &order)
{
  Process *process;

  if (this->_process.empty() || (process = findProcess()) == nullptr)
    process = this->createProcess();
  process->sendOrder(order);
}

Plazza::Process *Plazza::OrderDispatcher::findProcess()
{
  for (std::vector<Process *>::iterator it = this->_process.begin(); it != this->_process.end(); it++)
    if ((*it)->canAcceptOrder())
      return (*it);
  return nullptr;
}

Plazza::Process *Plazza::OrderDispatcher::createProcess()
{
  this->_process.push_back(new Process(this->_maxThreads));
  return this->_process.back();
}
