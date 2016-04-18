#ifndef CPP_PLAZZA_ISAFEQUEUE_HPP
#define CPP_PLAZZA_ISAFEQUEUE_HPP

template<typename T>
class ISafeQueue
{
 public:
  virtual ~ISafeQueue(void)
  { }

  virtual int pop(void) = 0;

  virtual void push(const T value) = 0;

  virtual bool tryPop(T *value) = 0;
};

#endif
