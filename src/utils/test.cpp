#include <Fifo.hpp>

int main()
{
  try
    {
      Fifo foo("LOOOL");
      foo.writeIn("LOL");
      std::cout << foo.readIn() << std::endl;
    }
  catch (std::exception &e)
    {
      std::cerr << e.what() << std::endl;
    }
  return 0;
}