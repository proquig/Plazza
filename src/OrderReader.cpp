//
// Created by pogam-_g on 4/11/16.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "OrderReader.h"

Plazza::OrderReader::OrderReader(std::queue<IOrder *> orders) : orders(orders){
    std::string line;
    while (std::cin)
    {
        std::getline(std::cin, line);
        parseLine(line);
    }
}

void Plazza::OrderReader::parseCommand(const std::string &command) {
    std::vector<std::string> files;
    std::string type;
    IOrder *order;

    // TODO :create order

    this->orders.push(order);
}

void Plazza::OrderReader::parseLine(const std::string &line) {
    std::vector<std::string> commands;

    // TODO : create commands

    for (std::vector<std::string>::iterator it; it != commands.end(); it++)
        parseCommand(*it);
}

