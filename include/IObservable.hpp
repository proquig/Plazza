//
// Created by pogam-_g on 20/04/16.
//

#ifndef CPP_PLAZZA_IOBSERVABLE_HPP
#define CPP_PLAZZA_IOBSERVABLE_HPP

#include <cstddef>
#include "IObserver.hpp"

class IObservable
{
 public:
  virtual ~IObservable() {}

  virtual void addObserver(IObserver *obs) = 0;

  virtual void deleteObserver(IObserver *obs) = 0;

 protected:
  virtual void notify(void) = 0;
};

#endif //CPP_PLAZZA_IOBSERVABLE_HPP
