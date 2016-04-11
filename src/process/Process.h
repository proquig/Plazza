//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_PROCESS_H
#define CPP_PLAZZA_PROCESS_H


#include <queue>
#include <thread>
#include "../IOrder.h"

namespace Plazza {
    class Process {
        unsigned long maxThreads;
        std::queue<IOrder *> orders;
        pid_t pid;
        std::vector<std::thread> threads;

    public:
        Process(unsigned int maxThreads);

        ~Process();

        bool canAcceptOrder();

        void pushOrder(IOrder *order);

        void deleteOrder();
    };
}


#endif //CPP_PLAZZA_PROCESS_H
