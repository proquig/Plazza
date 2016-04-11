//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_MAIN_H
#define CPP_PLAZZA_MAIN_H


#include <queue>
#include "IOrder.h"
#include "Process.h"
#include "OrderReader.h"

namespace Plazza {
    class Main {
        std::queue<IOrder *> orders;
        std::vector<Process> process;
        unsigned int MaxThreads;
        OrderReader reader;
    };
}


#endif //CPP_PLAZZA_MAIN_H
