#include <iostream>

template<typename T>
class ISafeQueue
{
 public:
  virtual ~ISafeQueue(void);

  virtual int pop(void) = 0;

  virtual void push(const T value) = 0;

  virtual bool tryPop(const T *value) = 0;
};

template<typename T>
ISafeQueue<T>::~ISafeQueue()
{ }
