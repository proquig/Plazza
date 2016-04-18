//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_ORDERREADER_H
#define CPP_PLAZZA_ORDERREADER_H


#include <thread>
#include <queue>
#include "orders/IOrder.h"

namespace Plazza
{
  class OrderReader
  {
    std::queue<IOrder *> orders;

    std::vector<std::string> commands;

   public:
    OrderReader();

    const std::vector<std::string> &getCommands() const;

   private:
    void parseLine(const std::string &line);

    void parseCommand(const std::string &command);
  };
}


#endif //CPP_PLAZZA_ORDERREADER_H
