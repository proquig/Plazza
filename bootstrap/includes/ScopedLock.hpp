/*
** ScopedLock.hpp for PLAZZA in /home/cloquet/Documents/cpp/PLAZZA
**
** Made by Cloquet
** Login   <cloquet@epitech.net>
**
** Started on  Wed Apr 06 16:47:51 2016 Cloquet
** Last update Wed Apr 06 17:01:15 2016 Cloquet
*/

#ifndef SCOPEDLOCK_HPP
#define SCOPEDLOCK_HPP

#include "Mutex.hpp"

class ScopedLock
{
private:
    Mutex _mutex;

public:
  ScopedLock (const Mutex &);
  virtual ~ScopedLock ();

    ScopedLock();
};

#endif
