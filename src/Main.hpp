//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_MAIN_HPP
#define CPP_PLAZZA_MAIN_HPP

#include <ISafeQueue.hpp>
#include <IObserver.hpp>
#include <list>
#include "IOrder.hpp"
#include "OrderReader.hpp"
#include "process/OrderDispatcher.hpp"

namespace Plazza
{
  class Main : public IObserver
  {
    ISafeQueue<IOrder *> *_ordersQueue;
    std::clock_t *_lastPop;
    OrderDispatcher *_orderDispatcher;
    OrderReader *_orderReader;

   public:

    Main(int argc, char *argv[]);

    ~Main();

    virtual void update() const;
   private:

    void updateClock();

    IOrder *getOrder(void);

    void usage(const char *name);
  };
}

#endif //CPP_PLAZZA_MAIN_HPP
