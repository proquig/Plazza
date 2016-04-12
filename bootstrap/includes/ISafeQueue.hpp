#include <iostream>

template <typename T>
class ISafeQueue
{
  public:
  virtual ~ISafeQueue(void);
  virtual void push(T value) = 0;
  virtual bool tryPop(T* value) = 0;
  virtual bool isFinished(void) = 0;
  virtual void setFinished(void) = 0;
};

template <typename T>
ISafeQueue<T>::~ISafeQueue()
{ }