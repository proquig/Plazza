//
// Created by pogam-_g on 4/11/16.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "OrderReader.h"

Plazza::OrderReader::OrderReader()
{
}

void				Plazza::OrderReader::parseCommand(const std::string &command)
{
  std::stringstream		commandStream(command);
  std::vector<std::string>	files;
  std::string			orderType;
  std::string			word;

  while (std::getline(commandStream, word, ' '))
    if (word.length())
      files.push_back(word);
  orderType = files.back();
  files.pop_back();
}

void Plazza::OrderReader::parseLine(const std::string &line)
{
  std::stringstream               lineStream(line);
  std::string                     command;

  while (std::getline(lineStream, command, ';'))
    if (command.length())
      parseCommand(command);
}

const std::vector<std::string> &Plazza::OrderReader::getCommands() const
{
  return commands;
}