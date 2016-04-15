//
// Created by cloquet on 13/04/16.
//

#ifndef CPP_PLAZZA_FORK_HPP
#define CPP_PLAZZA_FORK_HPP

#include <unistd.h>

namespace Plazza
{
  class Fork
  {
   private:
    pid_t _pid;

   public:
    Fork();

    ~Fork();

    pid_t &getPid() const;

    bool isChild() const;
  };
}


#endif //CPP_PLAZZA_FORK_HPP
