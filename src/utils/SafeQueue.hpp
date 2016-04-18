//
// Created by cloquet on 12/04/16.
//

#ifndef CPP_PLAZZA_SAFEQUEUE_HPP
#define CPP_PLAZZA_SAFEQUEUE_HPP

#include <queue>
#include <condition_variable>
#include "Exception.hpp"
#include "ISafeQueue.hpp"

template<typename T>
class SafeQueue : public ISafeQueue<T>
{
 private:
  std::queue<T> _queue;
  std::condition_variable _conVar;
  std::mutex _mutex;

 public:
  SafeQueue();

  ~SafeQueue(void);

  int pop(void);

  void push(const T value);

  bool tryPop(T *value);
};

template<typename T>
int SafeQueue<T>::pop(void)
{
  if (this->_queue.empty())
    { }//this->_conVar.wait();
  this->_queue.pop();
  return (0);
}

template<typename T>
SafeQueue<T>::SafeQueue()
{
  std::cout << "Création SafeQueue" << std::endl;
}

template<typename T>
SafeQueue<T>::~SafeQueue(void)
{
}

template<typename T>
void SafeQueue<T>::push(const T value)
{
  std::lock_guard<std::mutex> lock_guard(_mutex);
  this->_conVar.notify_one();
  this->_queue.push(value);
}

template<typename T>
bool SafeQueue<T>::tryPop(T *value)
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

#endif //CPP_PLAZZA_SAFEQUEUE_HPP
