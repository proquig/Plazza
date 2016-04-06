/*
** IMutex.cpp for plazza in /home/cloquet/Documents/cpp/PLAZZA
**
** Made by Cloquet
** Login   <cloquet@epitech.net>
**
** Started on  Tue Apr 05 17:30:19 2016 Cloquet
** Last update Wed Apr 06 16:28:41 2016 Cloquet
*/

#ifndef MUTEX_HPP
# define MUTEX_HPP
# include "IMutex.hpp"

class Mutex : public IMutex
{
  private:
    pthread_mutex_t mutex;

  public:
    Mutex();
    ~Mutex();
    void lock(void);
    void unlock(void);
    void trylock(void);
};

Mutex::Mutex()
{
  mutex = PTHREAD_MUTEX_INITIALIZER;
  std::cout << "Mutex init" << std::endl;
}

Mutex::~Mutex()
{
  pthread_mutex_destroy(&this->mutex);
}

void    Mutex::lock()
{
  pthread_mutex_lock(&this->mutex);
}

void    Mutex::trylock()
{
  pthread_mutex_trylock(&this->mutex);
}

void    Mutex::unlock()
{
  pthread_mutex_unlock(&this->mutex);
}

#endif
