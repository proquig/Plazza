//
// Created by pogam-_g on 14/04/16.
//

#include "Process.hpp"

Plazza::Process::Process(unsigned long maxThreads, unsigned int id) : id(id)
{
  this->_fifo[0] = new Fifo("plazza-" + std::to_string(id) + "-Main-Process");
  this->_fifo[1] = new Fifo("plazza-" + std::to_string(id) + "-Process-Main");
  /*this->_fork = new Fork;
  if (this->_fork->isChild())
    {
      this->_read = this->_fifo[0];
      this->_write = this->_fifo[1];
      this->_threadPool = new ThreadPool(maxThreads);
    }
  else
    {
      this->_read = this->_fifo[1];
      this->_write = this->_fifo[0];
    }*/
}

Plazza::Process::~Process()
{
  if (this->_fork->isChild())
    delete this->_threadPool;
  else
    {
      delete this->_read;
      delete this->_write;
    }
  delete this->_fork;
}
