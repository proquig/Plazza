#include "Client.hpp"

int main()
{
  try{
    Client client;
    
    client.Receive();
    
  }catch(std::exception &e)
    {
      std::cerr << e.what() << std::endl;
    }
  return 0;
}
