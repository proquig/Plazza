//
// Created by cloquet on 13/04/16.
//

#include "Fork.hpp"

Plazza::Fork::Fork() : _isChild(false)
{
  this->_pid = fork();
  if (this->_pid == 0)
    {
      this->_isChild = true;
      this->_pid = getpid();
    }
}

Plazza::Fork::~Fork()
{

}

bool Plazza::Fork::isChild() const
{
  return this->_isChild;
}

pid_t Plazza::Fork::get_pid() const
{
  return _pid;
}
