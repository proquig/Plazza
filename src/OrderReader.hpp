//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_ORDERREADER_H
#define CPP_PLAZZA_ORDERREADER_H

#include <thread>
#include <queue>
#include "orders/IOrder.hpp"
#include "utils/Factory.hpp"
#include "utils/ISafeQueue.hpp"

namespace Plazza
{
  class OrderReader
  {
    Factory<IOrder> _factory;
    ISafeQueue<IOrder *> *_orders;
    std::thread *_thread;
    bool _stop;

   public:
    OrderReader(ISafeQueue<IOrder *> *_ordersQueue);

    ~OrderReader();

    void stop();

   private:
    void reader();

    void parseLine(const std::string &line);

    void parseCommand(const std::string &command);
  };
}

#endif //CPP_PLAZZA_ORDERREADER_H
