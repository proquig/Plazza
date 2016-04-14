//
// Created by cloquet on 13/04/16.
//

#include "Fork.hpp"

Fork::Fork()
{
  this->_pid = fork();
}

pid_t &Fork::getPid() const
{
  return this->_pid;
}

Fork::~Fork()
{

}
