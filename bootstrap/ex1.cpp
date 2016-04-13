/*
** ex1.cpp for  in /home/cloquet/Documents/cpp/PLAZZA
**
** Made by Cloquet
** Login   <cloquet@epitech.net>
**
** Started on  Tue Apr 05 17:27:07 2016 Cloquet
** Last update Wed Apr 06 16:26:17 2016 Cloquet
*/

#include <stdlib.h>
#include <stdio.h>
#include "Mutex.hpp"
#include "SafeQueue.hpp"
#include "CondVar.hpp"

typedef struct  	count {
    int			var;
    Mutex		mutex;
    SafeQueue<int>	queue;
}               	count;

void init(count *c)
{
  c->var = 0;
}

void *increment_counter(void *N)
{
    count *param = static_cast<count *>(N);

    for (size_t i = 0; i < 1000000; i++)
    {
      param->mutex.lock();
      ++(param->var);
	param->queue.push(param->var);
      param->mutex.unlock();
    }
  return NULL;
}

void *decrement_counter(void *N)
{
  count *param = static_cast<count *>(N);

  for (size_t i = 0; i < 1000000; i++)
    {
      param->mutex.lock();
      ++(param->var);
      param->queue.tryPop(&param->var);
      param->mutex.unlock();
    }
  return NULL;
}

int main()
{
  ConVar	var;
  pthread_t pt1;
  pthread_t pt2;
  count       c;


  init(&c);
  printf("test avec mutex\n");
  pthread_create(&pt1, NULL, &increment_counter, &c);
  pthread_create(&pt2, NULL, &decrement_counter, &c);

  pthread_join(pt1, NULL);
  pthread_join(pt2, NULL);
  printf("test avec mutex :[%i]\n", c.var);

  c.queue.setFinished();
  if (c.queue.isFinished() == true)
    std::cout << "Ca marche bien" << std::endl;
  return 0;
}
