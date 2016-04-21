#include <iostream>
#include <vector>
#include <chrono>
#include "Parser.hpp"
#include "ThreadPool.h"

#define PHONE "0[1-9]([ ]?[0-9]){8}\"
int main(int ac, char **av)
{
  ThreadPool pool(4);
 
  auto results = pool.enqueue([](char **av){
      std::string				arg1;
      std::string				arg2;
      std::vector<std::string>			ret;
      std::vector<std::string>::iterator	it;
      arg1 = av[1];
      arg2 = av[2];      
      Parser			parser(arg1, arg2);
      ret = parser.parse();
      if (ret.size())
	for (it = ret.begin(); it != ret.end(); it++)
	  std::cout << *it << std::endl;
      else
	std::cout << "No match" << std::endl;
      return 1;
    }, av);
  
  std::cout << results.get() <<"\n";
  return 0;
}
