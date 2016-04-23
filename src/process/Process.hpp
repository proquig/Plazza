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
  class ThreadPool;

  class Process
  {
    std::clock_t _lastAction;
    ThreadPool *_pool;

   public:
    Fork *_fork;

    Process(size_t maxThreads, std::string message);

    ~Process();

    bool canAcceptOrder();

    void sendOrder(const IOrder &order);

    void stop();

   private:
    void parseMessage(const std::string message);

    IOrder *deserialize(const std::string &type, const std::string &file);

    static void parseFile(const IOrder &order);
  };
}

#endif //CPP_PLAZZA_PROCESS_HPP
