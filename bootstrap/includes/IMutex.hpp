/*
** IMutex.cpp for plazza in /home/cloquet/Documents/cpp/PLAZZA
**
** Made by Cloquet
** Login   <cloquet@epitech.net>
**
** Started on  Tue Apr 05 17:30:19 2016 Cloquet
** Last update Wed Apr 06 16:28:50 2016 Cloquet
*/

#ifndef IMUTEX_HPP
# define IMUTEX_HPP

#include <iostream>
#include <pthread.h>

class IMutex {
  public:
    virtual ~IMutex(){}
    virtual void lock(void) = 0;
    virtual void unlock(void) = 0;
    virtual void trylock(void) = 0;
};

#endif
