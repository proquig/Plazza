#include "Client.hpp"

int main()
{
  try{
    Client client;

      client.Send("XD");
  }catch(std::exception &e)
    {
      std::cerr << e.what() << std::endl;
    }
  return 0;
}
