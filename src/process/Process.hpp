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
    //ThreadPool *_pool;

   public:
    Process(size_t maxThreads);

    ~Process();

    bool canAcceptOrder();

    void sendOrder(const IOrder &order);

   private:
    void updateClock();

    void parseMessage(const std::string message);

    IOrder *deserialize(const std::string &type, const std::string &file);

    void parseFile(const IOrder &order);
  };
}

#endif //CPP_PLAZZA_PROCESS_HPP
