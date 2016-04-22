#ifndef CPP_PLAZZA_ISAFEQUEUE_HPP
#define CPP_PLAZZA_ISAFEQUEUE_HPP

namespace Plazza
{
  template<typename T>
  class ISafeQueue
  {
   public:
    virtual ~ISafeQueue(void)
    { }

    virtual T pop() = 0;

    virtual void push(const T value) = 0;

    virtual bool tryPop(T *value) = 0;

    virtual const T &front() const = 0;

    virtual const T &back() const = 0;

    virtual size_t size() const = 0;
  };
}

#endif
