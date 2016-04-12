//
// Created by cloquet on 12/04/16.
//

#ifndef CPP_PLAZZA_SAFEQUEUE_HPP
#define CPP_PLAZZA_SAFEQUEUE_HPP

#include "ISafeQueue.hpp"
#include <queue>

template <typename T>
class SafeQueue : public  ISafeQueue<T>
{
 private:
  std::queue<T> _queue;
  bool 		_finish;

 public:
  SafeQueue();
  ~SafeQueue(void);
  void push(T value);
  bool tryPop(T* value);
  bool isFinished(void);
  void setFinished(void);
};

template <typename T>
SafeQueue<T>::SafeQueue()
{
  std::cout << "Création SafeQueue" << std::endl;
}

template <typename T>
SafeQueue<T>::~SafeQueue(void)
{
  std::cout << "Destruction SafeQueue" << std::endl;
}

template <typename T>
void SafeQueue<T>::push(T value)
{
	this->_queue.push(value);
}

template <typename T>
bool SafeQueue<T>::tryPop(T* value)
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
