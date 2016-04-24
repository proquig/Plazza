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
#include <vector>
#include <ISafeQueue.hpp>
#include <IConnector.hpp>
#include "../utils/Fork.hpp"
#include "../utils/Fifo.hpp"

namespace Plazza
{
  class ThreadPool;

  class Process : public IObserver
  {
    std::time_t _lastAction;
    ThreadPool *_pool;
    size_t _ordersRunning;
    std::vector<IConnector *> _fifos;
    IConnector *_writer;
    IConnector *_reader;
    size_t _maxThreads;
    bool _terminated;

   public:
    Fork *_fork;

    Process(size_t maxThreads, int processId);

    ~Process();

    bool askCanAcceptOrder();

    void sendOrder(const IOrder &order);

    void stop();

    virtual void update();

   private:
    void timeTracker();

    void messageReader();

    void waitEnd(pid_t pid);

    void parseMessage(const std::string message);

    IOrder *deserialize(const std::string &type, const std::string &file);

    static void parseFile(const IOrder &order);
  };
}

#endif //CPP_PLAZZA_PROCESS_HPP
