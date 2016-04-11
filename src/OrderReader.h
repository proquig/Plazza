//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_ORDERREADER_H
#define CPP_PLAZZA_ORDERREADER_H


#include <thread>
#include <queue>
#include "IOrder.h"

namespace Plazza {
    class OrderReader {
        std::queue<IOrder *> orders;

    public:
        OrderReader(std::queue<IOrder *> orders);

    private:
        void parseLine(const std::string &line);

        void parseCommand(const std::string &command);
    };
}


#endif //CPP_PLAZZA_ORDERREADER_H
