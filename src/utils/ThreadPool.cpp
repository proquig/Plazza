//
// Created by cloquet on 13/04/16.
//

#include "ThreadPool.hpp"

ThreadPool::ThreadPool(const unsigned int &nb)
	: stop(false)
{
  for (size_t i = 0; i < nb; ++i)
    this->_workers.push_back(std::thread());
}

ThreadPool::~ThreadPool()
{
  stop = true;
  _condition.notify_all();
  for (size_t i = 0; i < _workers.size(); ++i)
    _workers[i].join();
}

template<class F>
void ThreadPool::enqueue(F func)
{
  {
    std::unique_lock<std::mutex> lock(this->_mutex);
    _tasks.push(std::function<void()>(func));
  }
  _condition.notify_one();
}
