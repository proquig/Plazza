//
// Created by pogam-_g on 4/11/16.
//

#include <iostream>
#include "Main.h"
#include "OrderReader.h"

int main(int argc, char *argv[]) {
    Plazza::Main(argc, argv);
}

Plazza::Main::Main(int argc, char **argv) {
    if (argc < 2)
        this->usage(argv[0]);
    else
        try {
            this->maxThreads = std::stoul(argv[1]);
        } catch (std::invalid_argument e) {
            this->usage(argv[0]);
        }

    OrderReader(this->orders);
}

Plazza::Main::~Main() {

}

void Plazza::Main::usage(char *name) {
    std::cerr << "Usage: " << name << " <threads>" << "\n"
    << "\t threads: a positive integer which determine the maximum number of threads per processus"
    << std::endl;
}

void Plazza::Main::pushOrder(IOrder *order) {
    this->orders.push(order);
}

