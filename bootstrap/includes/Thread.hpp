/*
** Thread.hpp for PLAZZA in /home/cloquet/Documents/cpp/PLAZZA
**
** Made by Cloquet
** Login   <cloquet@epitech.net>
**
** Started on  Wed Apr 06 17:09:00 2016 Cloquet
** Last update Wed Apr 06 17:17:54 2016 Cloquet
*/

#ifndef THREAD_HPP
#define  THREAD_HPP

#include <pthread.h>

class Thread
{
private:
  pthread_t pt1;

public:
  Thread ();
  virtual ~Thread ();
};

#endif
