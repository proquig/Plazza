//
// Created by pogam-_g on 4/11/16.
//

#include <unistd.h>
#include "Process.h"

Plazza::Process::Process(unsigned int maxThreads) : maxThreads(maxThreads) {
    this->pid = fork();
    if (this->pid == 0) {

    }
    // TODO : throw exception
}

Plazza::Process::~Process() {

}

bool Plazza::Process::canAcceptOrder() {
    return (this->orders.size() < this->maxThreads);
}

void Plazza::Process::pushOrder(IOrder *order) {
    if (canAcceptOrder())
        this->orders.push(order);
    else {} // TODO : throw exception
}

