//
// Created by pogam-_g on 22/04/16.
//

#ifndef CPP_PLAZZA_PROCESS_HPP
#define CPP_PLAZZA_PROCESS_HPP

#include <glob.h>
#include <IOrder.hpp>
#include <ctime>
#include "../utils/Fork.hpp"

namespace Plazza
{
  class Process
  {
    size_t _maxThreads;
    Fork *_fork;
    std::clock_t _lastAction;

   public:
    Process(size_t maxThreads);

    ~Process();

    bool canAcceptOrder();

    void sendOrder(IOrder *order);

   private:
    void updateClock();
  };
}

#endif //CPP_PLAZZA_PROCESS_HPP
