//
// Created by pogam-_g on 22/04/16.
//

#ifndef CPP_PLAZZA_PROCESS_HPP
#define CPP_PLAZZA_PROCESS_HPP

#include <glob.h>
#include <IOrder.hpp>

namespace Plazza
{
  class Process
  {
    size_t _maxThreads;

   public:
    Process(size_t maxThreads);

    ~Process();

    bool canAcceptOrder();

    void sendOrder(IOrder *order);
  };
}

#endif //CPP_PLAZZA_PROCESS_HPP
