//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_PROCESS_H
#define CPP_PLAZZA_PROCESS_H


#include <queue>
#include <thread>
#include "IOrder.h"

namespace Plazza {
    class Process {
        unsigned int maxThreads;
        std::queue<IOrder *const &> orders;
        pid_t pid;
        std::vector<std::thread> threads;

    public:
        Process(unsigned int maxThreads);

        bool canAcceptOrder();

        void addOrder(IOrder *order);

        void deleteOrder(IOrder *order);
    };
}


#endif //CPP_PLAZZA_PROCESS_H
