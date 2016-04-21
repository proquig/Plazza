//
// Created by pogam-_g on 4/11/16.
//

#include <algorithm>
#include "Main.hpp"
#include "utils/SafeQueue.hpp"

int main(int argc, char *argv[])
{
  Plazza::Main(argc, argv);
}

Plazza::Main::Main(int argc, char **argv) : _ordersQueue(new SafeQueue<IOrder *>()), _pid(0), _lastPop(new std::clock_t)
{
  if (argc < 2)
    this->usage(argv[0]);
  else
    try
      {
	this->_maxThreads = std::stoul(argv[1]);
      } catch (std::invalid_argument e)
      {
	this->usage(argv[0]);
      }
  new OrderReader(this->_ordersQueue);

}

Plazza::Main::~Main()
{
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

void Plazza::Main::usage(char *name)
{
  std::cerr << "Usage: " << name << " <threads>" << "\n"
  << "\t threads: a positive integer which determine the maximum number of threads per processus"
  << std::endl;
  exit(1);
}

void Plazza::Main::update() const
{
  // TODO: assign task
}
