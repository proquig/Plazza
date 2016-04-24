//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_ORDERREADER_H
#define CPP_PLAZZA_ORDERREADER_H

#include <thread>
#include <ISafeQueue.hpp>
#include <IObservable.hpp>
#include <IObservable.hpp>
#include <list>
#include "IOrder.hpp"
#include "utils/Factory.hpp"

namespace Plazza
{
  class OrderReader : public IObservable
  {
    Factory<IOrder> _factory;
    ISafeQueue<IOrder *> *_orders;
    std::thread *_thread;
    std::list<IObserver *> _observers;

   public:
    OrderReader(ISafeQueue<IOrder *> *_ordersQueue);

    ~OrderReader();

    void start();

    virtual void addObserver(IObserver *obs);

    virtual void deleteObserver(IObserver *obs);

   protected:

   private:
    virtual void notify(void);

    void reader();

    void parseLine(const std::string &line);

    void parseCommand(const std::string &command);
  };
}

#endif //CPP_PLAZZA_ORDERREADER_H
