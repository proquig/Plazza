//
// Created by cloquet on 13/04/16.
//

#include "ThreadPool.hpp"

Plazza::ThreadPool::ThreadPool(unsigned long theads)
	: _stop(false)
{
  for (size_t i = 0; i < theads; ++i)
    this->_workers.push_back(std::thread());
}

Plazza::ThreadPool::~ThreadPool()
{
  this->_stop = true;
  this->_condition.notify_all();
  for (size_t i = 0; i < this->_workers.size(); ++i)
    {
      if (this->_workers[i].joinable())
	this->_workers[i].join();
    }
}

template<class F>
void Plazza::ThreadPool::enqueue(F func)
{
  {
    std::unique_lock<std::mutex> lock(this->_mutex);
    this->_tasks.push(std::function<void()>(func));
  }
  this->_condition.notify_one();
}
