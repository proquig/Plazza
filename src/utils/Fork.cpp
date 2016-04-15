//
// Created by cloquet on 13/04/16.
//

#include "Fork.hpp"

Plazza::Fork::Fork()
{
  this->_pid = fork();
}

Plazza::Fork::~Fork()
{

}

pid_t &Plazza::Fork::getPid() const
{
  return this->_pid;
}

bool Plazza::Fork::isChild() const
{
  return this->_pid == 0;
}
