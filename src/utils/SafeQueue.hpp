//
// Created by cloquet on 12/04/16.
//

#ifndef CPP_PLAZZA_SAFEQUEUE_HPP
#define CPP_PLAZZA_SAFEQUEUE_HPP

#include "../../bootstrap/includes/ISafeQueue.hpp"
#include <queue>
#include "../../bootstrap/includes/CondVar.hpp"
#include "../../bootstrap/includes/Exception.hpp"

template <typename T>
class SafeQueue : public  ISafeQueue<T>
{
 private:
  std::queue<T> _queue;
  bool 		_finish;
  ConVar	_conVar;

 public:
  SafeQueue();
  ~SafeQueue(void);
  int pop(void);
  void push(const T value);
  bool tryPop(const T* value);
  bool isFinished(void);
  void setFinished(void);
};

template <typename T>
int SafeQueue<T>::pop(void)
{
  if (this->_finish)
    throw(exception("Can't fill an empty Queue."));
  if (this->_queue.empty())
    this->_conVar.wait();
  this->_queue.pop();
  return (0);
}

template <typename T>
SafeQueue<T>::SafeQueue()
{
  this->_finish = false;
  std::cout << "Création SafeQueue" << std::endl;
}

template <typename T>
SafeQueue<T>::~SafeQueue(void)
{
  std::cout << "Destruction SafeQueue" << std::endl;
}

template <typename T>
void SafeQueue<T>::push(const T value)
{
  this->_conVar.signal();
  this->_queue.push(value);
}

template <typename T>
bool SafeQueue<T>::tryPop(const T* value)
{
  if (this->_queue.empty())
    return false;
  this->_queue.pop();
}

template <typename T>
bool SafeQueue<T>::isFinished(void)
{
  return (this->_finish && this->_queue.empty());
}

template <typename T>
void SafeQueue<T>::setFinished(void)
{
  this->_finish = true;
}

#endif //CPP_PLAZZA_SAFEQUEUE_HPP
