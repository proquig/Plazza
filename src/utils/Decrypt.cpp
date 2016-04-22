//
// Decrypt.cpp for plazza in /home/proqui_g/rendu/cpp_plazza/src/utils
// 
// Made by Guillaume PROQUIN
// Login   <proqui_g@epitech.net>
// 
// Started on  Mon Apr 18 18:52:13 2016 Guillaume PROQUIN
// Last update Fri Apr 22 17:17:42 2016 Guillaume PROQUIN
//

#include "Decrypt.hpp"

Decrypt::Decrypt(const std::string& regex, const std::string& filename) : Parser(regex, filename)
{
}

Decrypt::~Decrypt()
{
}

std::vector<std::string>	Decrypt::decryptCaesar(const std::string& line)
{
  std::string			line_tmp(line);
  int				i;
  unsigned int			j;

  i = 0;
  while (++i < 256)
    {
      j = 0;
      while (j < line.length())
	{
	  line_tmp[j]++;
	  j++;
	}
      if (Regex::match(this->getRegex(), line_tmp))
	return (this->parseLine(line_tmp));
    }
  return (std::vector<std::string>());
}

std::vector<std::string>	Decrypt::decryptXor(const std::string& line)
{
  std::string			line_tmp;
  char				key[] = {0, 0};
  int				i;
  unsigned int			j;

  i = 0;
  while (++i <= 65536)
    {
      key[0] = i / 256;
      key[1] = i % 256;
      j = 0;
      line_tmp = line;
      if (IS_PRINTABLE((char)(key[0] ^ line_tmp[0])) && IS_PRINTABLE((char)(key[1] ^ line_tmp[1])))
	{
	  while (j < line_tmp.length())
	    {
	      line_tmp[j] ^= (i < 256) ? key[1] : key[j % 2];
	      j++;
	    }
	  if (Regex::match(this->getRegex(), line_tmp))
	    return (this->parseLine(line_tmp));
	}
    }
  return (std::vector<std::string>());
}

std::vector<std::string>	Decrypt::decrypt()
{
  std::vector<std::string>	ret;
  std::vector<std::string>	tmp;
  std::string			line;

  while (std::getline(this->getFile(), line))
    {
      tmp.clear();
      tmp = this->parseLine(line);
      ret.insert(ret.end(), tmp.begin(), tmp.end());
      if (tmp.empty())
	{
	  tmp = this->decryptCaesar(line);
	  ret.insert(ret.end(), tmp.begin(), tmp.end());
	}
      if (tmp.empty())
	{
	  tmp = this->decryptXor(line);
	  ret.insert(ret.end(), tmp.begin(), tmp.end());
	}
    }
  return ret;
}
