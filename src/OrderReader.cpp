//
// Created by pogam-_g on 4/11/16.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "OrderReader.h"

void				Plazza::OrderReader::OrderReader(std::queue<IOrder *> orders) : orders(orders)
{
  /*
    std::string line;
    while (std::cin)
    {
    std::getline(std::cin, line);
    parseLine(line);
    }
  */
}

void				Plazza::OrderReader::parseCommand(const std::string &command)
{
  std::vector<std::string>	files;
  std::stringstream		commandStream(command);
  std::string			type;
  IOrder			*order;

  while (std::getline(commandStream, word, ' '))
    if (word.length())
      files.push_back(word);
  order = files.back();
  files.pop_back();
  //this->orders.push(order);
}

void Plazza::OrderReader::parseLine(const std::string &line)
{
  //std::vector<std::string> commands;

  //for (std::vector<std::string>::iterator it; it != commands.end(); it++)
  //parseCommand(*it);
  std::stringstream               lineStream(line);
  std::string                     command;

  while (std::getline(lineStream, command, ';'))
    if (command.length())
      parseCommand(command);
}
