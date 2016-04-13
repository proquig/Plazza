//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_MAIN_H
#define CPP_PLAZZA_MAIN_H


#include <queue>
#include "IOrder.h"
#include "process/Process.h"

namespace Plazza
{
  class Main
  {
    std::queue<IOrder *> orders;
    std::vector<Process> process;
    unsigned long maxThreads;

   public:
    Main(int argc, char *argv[]);

    ~Main();

    void createProcess();

   private:
    void usage(char *name);
  };
}


#endif //CPP_PLAZZA_MAIN_H
