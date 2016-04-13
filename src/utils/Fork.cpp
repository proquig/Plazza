//
// Created by cloquet on 13/04/16.
//

#include "Fork.hpp"

Fork::Fork()
{
  _pid = fork();
}

pid_t &Fork::getPid() const
{
  return _pid;
}

Fork::~Fork()
{

}