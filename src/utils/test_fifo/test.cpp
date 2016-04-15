#include <Fifo.hpp>

#include <stdio.h>

int     main()
{
int  pid =fork();
  if (pid == 0)
    {
      try
	{
	  Fifo t("testers"); //Construction test
	}
      catch (std::exception *e)
	{
	  std::cout << e->what() << std::endl;
	}
    }
  else
    std::cout << "Im in daddy" << std::endl;
  return (0);
}