//
// Created by pogam-_g on 4/11/16.
//

#include "Process.h"

Plazza::Process::Process(unsigned long maxThreads) : maxThreads(maxThreads)
{
}

Plazza::Process::~Process()
{

}

bool Plazza::Process::canAcceptOrder()
{
  return (this->orders.size() < this->maxThreads);
}

void Plazza::Process::pushOrder(IOrder *order)
{
  if (this->canAcceptOrder())
    this->orders.push(order);
  else
    { } // TODO : throw exception
}

