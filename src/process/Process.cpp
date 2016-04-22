//
// Created by pogam-_g on 22/04/16.
//

#include <iostream>
#include "Process.hpp"

Plazza::Process::Process(size_t maxThreads) : _maxThreads(maxThreads)
{
}

Plazza::Process::~Process()
{
}

bool Plazza::Process::canAcceptOrder()
{
  return false;
}

void Plazza::Process::sendOrder(IOrder *order)
{
  std::cout << *order << std::endl;
}
