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
#include <IObservable.hpp>
#include <list>
#include <algorithm>
#include "../utils/SafeQueue.hpp"
#include "Process.hpp"

namespace Plazza
{
  class Process;

  class ThreadPool : public IObservable
  {
    std::vector<std::thread *> _threads;
    ISafeQueue<IOrder*> *_orders;
    std::list<IObserver *> _observers;
    bool _stop;
    void (*_func)(const IOrder &);

   public:
    ThreadPool(size_t maxThreads, void (*)(const IOrder &));

    ~ThreadPool();

    void enqueue(IOrder &order);

    void stop();

    virtual void addObserver(IObserver *obs);

    virtual void deleteObserver(IObserver *obs);

   protected:
    virtual void notify(void);

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
  }

  void ThreadPool::enqueue(IOrder &order)
  {
    this->_orders->push(&order);
  }

  void ThreadPool::stop()
  {
    this->_stop = true;
  }

  void ThreadPool::addObserver(IObserver *obs)
  {
    this->_observers.push_back(obs);
  }

  void ThreadPool::deleteObserver(IObserver *obs)
  {
    const std::list<IObserver *>::iterator &it = std::find(this->_observers.begin(), this->_observers.end(), obs);
    if (it != this->_observers.end())
      this->_observers.erase(it);
  }

  void ThreadPool::notify(void)
  {
    for (std::list<IObserver *>::iterator it = this->_observers.begin(); it != this->_observers.end(); it++)
      (*it)->update();
  }

  void ThreadPool::run()
  {
    IOrder *order;

    while (!this->_stop)
      {
	if (this->_orders->tryPop(&order))
	  {
	    _func(*order);
	    notify();
	  }
	else
	  usleep(100);
      }
  }
}

#endif //CPP_PLAZZA_THREADPOOL_HPP
