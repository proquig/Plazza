#include	"Regex.hpp"

int					main(int ac, char **av)
{
  std::vector<std::string>::iterator	it;
  std::vector<std::string>		ret;
  std::string				arg1;
  std::string				arg2;
  regex_t				reg;

  (void)ac;
  if (av[1] && av[2])
    {
      arg1 = av[1];
      arg2 = av[2];
      reg = Regex::compile(arg1);
      std::cout << Regex::match(reg, arg2) << std::endl;
      ret = Regex::extract(reg, arg2);
      if (ret.size())
	for (it = ret.begin(); it != ret.end(); it++)
	  std::cout << *it << std::endl;
      else
	std::cout << "No match" << std::endl;
    }
  else
    std::cerr << "Usage " << av[0] << " regex file" << std::endl;
}
