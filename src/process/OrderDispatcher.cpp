//
// Created by pogam-_g on 22/04/16.
//

#include <iostream>
#include <wait.h>
#include "OrderDispatcher.hpp"

Plazza::OrderDispatcher::OrderDispatcher(size_t maxThreads) : _maxThreads(maxThreads)
{
}

Plazza::OrderDispatcher::~OrderDispatcher()
{
  for (std::list<Process *>::iterator it = this->_process.begin(); it != this->_process.end(); it++)
    waitpid((*it)->_fork->get_pid(), NULL, 0);
}

void Plazza::OrderDispatcher::dispatch(const IOrder &order)
{
  Process *process;
  pid_t mainPid = getpid();

  if (this->_process.empty() || (process = findProcess()) == nullptr)
    process = this->createProcess(order);
  if (mainPid == getpid())
    process->sendOrder(order);
}

Plazza::Process *Plazza::OrderDispatcher::findProcess()
{
  for (std::list<Process *>::iterator it = this->_process.begin(); it != this->_process.end(); it++)
    if ((*it)->canAcceptOrder())
      return (*it);
  return nullptr;
}

Plazza::Process *Plazza::OrderDispatcher::createProcess(const IOrder &order)
{
  this->_process.push_back(new Process(this->_maxThreads, order.getOrder() + " " + order.getFile()));
  return this->_process.back();
}
