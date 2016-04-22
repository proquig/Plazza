//
// Created by cloquet on 12/04/16.
//

#ifndef CPP_PLAZZA_SAFEQUEUE_HPP
#define CPP_PLAZZA_SAFEQUEUE_HPP

#include <queue>
#include <condition_variable>
#include <ISafeQueue.hpp>
#include "Exception.hpp"

namespace Plazza
{
  template<typename T>
  class SafeQueue : public ISafeQueue<T>
  {
   private:
    std::queue<T> _queue;
    std::mutex _mutex;
    std::condition_variable _condVar;

   public:
    SafeQueue();

    virtual ~SafeQueue(void);

    virtual void push(const T value);

    virtual bool tryPop(T *value);

    virtual T pop();

    virtual const T &front() const;

    virtual const T &back() const;

    virtual size_t size() const;
  };
}

template<typename T>
Plazza::SafeQueue<T>::SafeQueue()
{
}

template<typename T>
Plazza::SafeQueue<T>::~SafeQueue(void)
{
}

template<typename T>
void Plazza::SafeQueue<T>::push(const T value)
{
  std::lock_guard<std::mutex> lock_guard(_mutex);
  this->_condVar.notify_one();
  this->_queue.push(value);
}

template<typename T>
bool Plazza::SafeQueue<T>::tryPop(T *value)
{
  if (this->_queue.empty())
    return false;
  else
    {
      std::lock_guard<std::mutex> lock_guard(_mutex);
      *value = this->_queue.front();
      this->_queue.pop();
      return true;
    }
}

template<typename T>
T Plazza::SafeQueue<T>::pop()
{
  IOrder *order;

  std::unique_lock<std::mutex> lock(_mutex);
  if (this->_queue.empty())
    this->_condVar.wait(lock);
  order = this->front();
  this->_queue.pop();
  return (order);
}

template<typename T>
const T &Plazza::SafeQueue<T>::front() const
{
  return this->_queue.front();
}

template<typename T>
const T &Plazza::SafeQueue<T>::back() const
{
  return this->_queue.back();
}

template<typename T>
size_t Plazza::SafeQueue<T>::size() const
{
  return this->_queue.size();
}

#endif //CPP_PLAZZA_SAFEQUEUE_HPP
