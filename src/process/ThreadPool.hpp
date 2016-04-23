//
// Created by pogam-_g on 23/04/16.
//

#ifndef CPP_PLAZZA_THREADPOOL_HPP
#define CPP_PLAZZA_THREADPOOL_HPP

#include <cstddef>
#include <thread>
#include <vector>
#include <IOrder.hpp>
#include <queue>
#include <ISafeQueue.hpp>
#include "../utils/SafeQueue.hpp"
#include "Process.hpp"

namespace Plazza
{
  class Process;

  class ThreadPool
  {
    std::vector<std::thread *> _threads;
    ISafeQueue<IOrder*> *_orders;
    bool _stop;
    void (*_func)(const IOrder &);

   public:
    ThreadPool(size_t maxThreads, void (*)(const IOrder &));

    ~ThreadPool();

    void enqueue(IOrder &order);

    void stop();

   private:
    void run();
  };

  ThreadPool::ThreadPool(size_t maxThreads, void (*func)(const IOrder &))
	  : _orders(new SafeQueue<IOrder*>()), _stop(false), _func(func)
  {
    for (size_t i = 0; i < maxThreads; i++)
      {
	this->_threads.push_back(new std::thread(&ThreadPool::run, this));
	usleep(100);
      }
  }

  ThreadPool::~ThreadPool()
  {
    for (std::vector<std::thread *>::iterator it = this->_threads.begin(); it != this->_threads.end(); it++)
      if ((*it)->joinable())
	(*it)->join();
    std::cout << "ThreadPool: destroy" << std::endl;
  }

  void ThreadPool::enqueue(IOrder &order)
  {
    this->_orders->push(&order);
  }

  void ThreadPool::run()
  {
    IOrder *order;

    while (!this->_stop)
      {
	if (this->_orders->tryPop(&order))
	  {
	    _func(*order);
	  }
	else
	  usleep(100);
      }
  }

  void ThreadPool::stop()
  {
    this->_stop = true;
  }
}

#endif //CPP_PLAZZA_THREADPOOL_HPP
