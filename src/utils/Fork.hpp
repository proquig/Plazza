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
    bool _isChild;

   public:
    Fork();

    ~Fork();

    bool isChild() const;

    pid_t get_pid() const;
  };
}


#endif //CPP_PLAZZA_FORK_HPP
