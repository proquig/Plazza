//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_MAIN_HPP
#define CPP_PLAZZA_MAIN_HPP

#include <ISafeQueue.hpp>
#include <IObserver.hpp>
#include <list>
#include "orders/IOrder.hpp"
#include "OrderReader.hpp"
#include "process/Process.hpp"

namespace Plazza
{
  class Main : public IObserver
  {
    ISafeQueue<IOrder *> *_ordersQueue;
    unsigned long _maxThreads;
    std::vector<Process *> _process;
    unsigned int _pid;
    std::clock_t *_lastPop;

   public:
    Main(int argc, char *argv[]);

    ~Main();

    virtual void update() const;

   private:
    void updateClock();

    IOrder *getOrder(void);

    void usage(char *name);
  };
}

#endif //CPP_PLAZZA_MAIN_HPP
