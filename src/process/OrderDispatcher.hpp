//
// Created by pogam-_g on 22/04/16.
//

#ifndef CPP_PLAZZA_ORDERDISPATCHER_HPP
#define CPP_PLAZZA_ORDERDISPATCHER_HPP

#include <IOrder.hpp>
#include <list>
#include "Process.hpp"

namespace Plazza
{
  class OrderDispatcher
  {
    std::list<Process *> _process;
    size_t _maxThreads;

   public:
    OrderDispatcher(size_t _maxThreads);

    ~OrderDispatcher();

    void dispatch(const IOrder &order);

   private:
    Process * findProcess();

    Plazza::Process *createProcess();
  };
}

#endif //CPP_PLAZZA_ORDERDISPATCHER_HPP
