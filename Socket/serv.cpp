#include "Socket.hpp"

int main()
{
  try{
      Socket socket(4);
    }
  catch (std::exception &e)
    {
      std::cerr << e.what() << std::endl;
    }
  return 0;
}