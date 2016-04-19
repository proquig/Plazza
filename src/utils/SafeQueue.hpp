//
// Created by cloquet on 12/04/16.
//

#ifndef CPP_PLAZZA_SAFEQUEUE_HPP
#define CPP_PLAZZA_SAFEQUEUE_HPP

#include <queue>
#include <condition_variable>
#include "Exception.hpp"
#include "ISafeQueue.hpp"

namespace Plazza
{
  template<typename T>
  class SafeQueue : public ISafeQueue<T>
  {
   private:
    std::queue<T> _queue;
    std::condition_variable _conVar;
    std::mutex _mutex;

   public:
    SafeQueue();

    virtual ~SafeQueue(void);

    virtual void push(const T value);

    virtual bool tryPop(T *value);

    virtual int pop(void);

    virtual T &front();

    virtual T &back();
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
  this->_conVar.notify_one();
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
int Plazza::SafeQueue<T>::pop(void)
{
  if (this->_queue.empty())
    { }//this->_conVar.wait();
  this->_queue.pop();
  return (0);
}

template<typename T>
T &Plazza::SafeQueue<T>::front()
{
  return this->_queue.front();
}

template<typename T>
T &Plazza::SafeQueue<T>::back()
{
  return this->_queue.back();
}

#endif //CPP_PLAZZA_SAFEQUEUE_HPP
