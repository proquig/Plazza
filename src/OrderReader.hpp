//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_ORDERREADER_H
#define CPP_PLAZZA_ORDERREADER_H


#include <thread>
#include <queue>
#include "orders/IOrder.hpp"
#include "utils/Factory.hpp"

namespace Plazza
{
  class OrderReader
  {
    Factory<IOrder> _factory;
    std::queue<IOrder *> _orders;

   public:
    OrderReader();

   private:
    void parseLine(const std::string &line);

    void parseCommand(const std::string &command);
  };
}


#endif //CPP_PLAZZA_ORDERREADER_H
