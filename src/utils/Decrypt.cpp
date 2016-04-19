//
// Decrypt.cpp for plazza in /home/proqui_g/rendu/cpp_plazza/src/utils
// 
// Made by Guillaume PROQUIN
// Login   <proqui_g@epitech.net>
// 
// Started on  Mon Apr 18 18:52:13 2016 Guillaume PROQUIN
// Last update Tue Apr 19 10:49:09 2016 Guillaume PROQUIN
//

#include "Decrypt.hpp"

Decrypt::Decrypt(const std::string& regex, const std::string& filename) : Parser(regex, filename)
{
}

Decrypt::~Decrypt()
{
}

std::vector<std::string>	Decrypt::decryptCaesar(std::string& line)
{
  std::vector<std::string>	ret;
  std::vector<std::string>	tmp;
  int				i;
  unsigned int			j;

  i = 0;
  while (++i < 256)
    {
      j = 0;
      while (j < line.length())
	{
	  line[j]++;
	  j++;
	}
      tmp = this->parseLine(line);
      ret.insert(ret.begin(), tmp.begin(), tmp.end());
    }
  return ret;
}

//std::vector<std::string>	Decrypt::decryptXor(const std::string& line, int key)
//{
//}

std::vector<std::string>	Decrypt::decrypt()
{
  std::vector<std::string>	ret;
  std::vector<std::string>	tmp;
  std::string			line;

  while (std::getline(Parser::getFile(), line))
    {
      tmp = Parser::parseLine(line);
      ret.insert(ret.end(), tmp.begin(), tmp.end());
      tmp = this->decryptCaesar(line);
      ret.insert(ret.end(), tmp.begin(), tmp.end());
    }
  return ret;
}
