//
// Created by pogam-_g on 4/11/16.
//

#include <algorithm>
#include "Main.hpp"
#include "utils/SafeQueue.hpp"
#include "utils/Parser.hpp"

int main(int argc, char *argv[])
{
  Plazza::Main(argc, argv);
}

Plazza::Main::Main(int argc, char **argv) : _ordersQueue(new SafeQueue<IOrder *>()), _lastPop(new std::clock_t),
					    _mainPid(getpid())
{
  size_t maxThreads;

  if (argc < 2)
    this->usage(argv[0]);
  else
    try
      {
	maxThreads = std::stoul(argv[1]);
      } catch (std::invalid_argument e)
      {
	this->usage(argv[0]);
      }
  this->_orderReader = new OrderReader(this->_ordersQueue);
  this->_orderReader->addObserver(this);
  this->_orderDispatcher = new OrderDispatcher(maxThreads);
  this->_orderReader->start();
}

Plazza::Main::~Main()
{
  delete this->_orderReader;
  delete this->_orderDispatcher;
}

void Plazza::Main::updateClock()
{
  delete this->_lastPop;
  this->_lastPop = new std::clock_t;
}

Plazza::IOrder *Plazza::Main::getOrder(void)
{
  IOrder *order;

  if (this->_ordersQueue->tryPop(&order))
    {
      this->updateClock();
      return order;
    }
  else
    return nullptr;
}

void Plazza::Main::update() const
{
  IOrder *order;

  if (this->_mainPid == getpid())
    {
      order = this->_ordersQueue->pop();
      this->_orderDispatcher->dispatch(*order);
    }
}

void Plazza::Main::usage(const char *name)
{
  std::cerr << "Usage: " << name << " <threads>" << "\n"
  << "\t threads: a positive integer which determine the maximum number of threads per processus"
  << std::endl;
  exit(1);
}
