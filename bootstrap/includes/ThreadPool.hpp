//
// Created by cloquet on 13/04/16.
//

#ifndef CPP_PLAZZA_THREADPOOL_HPP
#define CPP_PLAZZA_THREADPOOL_HPP

#include <functional>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <vector>

#include "../../src/utils/SafeQueue.hpp"

class ThreadPool
{
  SafeQueue<std::function<void ()> > 	_tasks;
  std::vector<std::thread> 		_workers;
  std::mutex				_mutex;
  std::condition_variable 		_condition;
  bool 					stop;

 public:
	ThreadPool(const unsigned int &);
  	template <class F>
	void enqueue(F func);
  	~ThreadPool();
};

ThreadPool::ThreadPool(const unsigned int &nb)
	: stop(false)
{
  for(size_t i = 0; i < nb; ++i)
    this->_workers.push_back(std::thread(//TODO));
}

template <class F>
void ThreadPool::enqueue(F func)
{
  {
    std::unique_lock<std::mutex> lock(this->_mutex);
    _tasks.push(std::function<void ()> (func));
  }
  _condition.notify_one();
}

ThreadPool::~ThreadPool()
{
  stop = true;
  condition.notify_all();
  for(size_t i = 0;i<workers.size();++i)
    workers[i].join();
}

#endif //CPP_PLAZZA_THREADPOOL_HPP
