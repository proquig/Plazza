//
// Created by pogam-_g on 20/04/16.
//

#ifndef CPP_PLAZZA_IOBSERVER_HPP
#define CPP_PLAZZA_IOBSERVER_HPP

class IObservable;

class IObserver
{
 public:
  virtual ~IObserver() {}

  virtual void update() const = 0;
};

#endif //CPP_PLAZZA_IOBSERVER_HPP
