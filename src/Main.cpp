//
// Created by pogam-_g on 4/11/16.
//

#include <iostream>
#include "Main.hpp"
#include "utils/Fork.hpp"
#include "utils/SafeQueue.hpp"

int main(int argc, char *argv[])
{
  Plazza::Main(argc, argv);
}

Plazza::Main::Main(int argc, char **argv) : _ordersQueue(new SafeQueue<IOrder *>())
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
  this->_orderReader = new OrderReader(this->_ordersQueue);
}

Plazza::Main::~Main()
{
  delete this->_orderReader;
  delete this->_ordersQueue;
}

void Plazza::Main::usage(char *name)
{
  std::cerr << "Usage: " << name << " <threads>" << "\n"
  << "\t threads: a positive integer which determine the maximum number of threads per processus"
  << std::endl;
  exit(1);
}
