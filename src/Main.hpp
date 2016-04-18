//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_MAIN_HPP
#define CPP_PLAZZA_MAIN_HPP

#include "orders/IOrder.hpp"
#include "utils/ISafeQueue.hpp"

namespace Plazza
{
  class Main
  {
    ISafeQueue<IOrder *> *_ordersQueue;
    unsigned long _maxThreads;

   public:
    Main(int argc, char *argv[]);

    ~Main();

   private:
    void usage(char *name);
  };
}

#endif //CPP_PLAZZA_MAIN_HPP
