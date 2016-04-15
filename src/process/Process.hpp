//
// Created by pogam-_g on 14/04/16.
//

#ifndef CPP_PLAZZA_PROCESS_HPP
#define CPP_PLAZZA_PROCESS_HPP


#include "../utils/Fork.hpp"
#include "../utils/Fifo.hpp"
#include "../utils/ThreadPool.hpp"

namespace Plazza
{
  class Process
  {
    unsigned int id;
    Fork *_fork;
    Fifo *_fifo[2];
    Fifo *_read;
    Fifo *_write;
    ThreadPool *_threadPool;

   public:
    Process(unsigned int maxThreads, unsigned int id);

    virtual ~Process();
  };
}


#endif //CPP_PLAZZA_PROCESS_HPP
