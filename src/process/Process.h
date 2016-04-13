//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_PROCESS_H
#define CPP_PLAZZA_PROCESS_H


#include <queue>
#include <thread>
#include "../IOrder.h"

namespace Plazza
{
  class Process
  {
    unsigned long maxThreads;
    std::queue<IOrder *> orders;
    std::vector<std::thread> workers;

   public:
    Process(unsigned long maxThreads);

    ~Process();

    bool canAcceptOrder();

    void pushOrder(IOrder *order);
  };
}


#endif //CPP_PLAZZA_PROCESS_H
