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

bool Plazza::Fork::isChild() const
{
  return this->_pid == 0;
}
