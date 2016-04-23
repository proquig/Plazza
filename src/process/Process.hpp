//
// Created by pogam-_g on 22/04/16.
//

#ifndef CPP_PLAZZA_PROCESS_HPP
#define CPP_PLAZZA_PROCESS_HPP

#include <glob.h>
#include <IOrder.hpp>
#include <ctime>
#include <IObserver.hpp>
#include <thread>
#include "../utils/Fork.hpp"

namespace Plazza
{
  class ThreadPool;

  class Process : public IObserver
  {
    std::time_t _lastAction;
    ThreadPool *_pool;
    size_t _ordersRunning;
    std::thread *_timeTracker;

   public:
    Fork *_fork;

    Process(size_t maxThreads, std::string message);

    ~Process();

    bool canAcceptOrder();

    void sendOrder(const IOrder &order);

    void stop();

    virtual void update();

   private:
    void timeTracker();

    void parseMessage(const std::string message);

    IOrder *deserialize(const std::string &type, const std::string &file);

    static void parseFile(const IOrder &order);
  };
}

#endif //CPP_PLAZZA_PROCESS_HPP
