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

#include "SafeQueue.hpp"

class ThreadPool
{
  SafeQueue<std::function<void()> > _tasks;
  std::vector<std::thread> _workers;
  std::mutex _mutex;
  std::condition_variable _condition;
  bool stop;

 public:
  ThreadPool(const unsigned int &);

  ~ThreadPool();

  template<class F>
  void enqueue(F func);
};

#endif //CPP_PLAZZA_THREADPOOL_HPP
