//
// Decrypt.hpp for plazza in /home/proqui_g/rendu/cpp_plazza/src/utils
// 
// Made by Guillaume PROQUIN
// Login   <proqui_g@epitech.net>
// 
// Started on  Mon Apr 18 18:52:23 2016 Guillaume PROQUIN
// Last update Tue Apr 19 13:24:39 2016 Guillaume PROQUIN
//

#ifndef		__DECRYPT_HPP__
# define	__DECRYPT_HPP__

# include	<iostream>
# include	<fstream>
# include	<vector>
# include	"Parser.hpp"

class		Decrypt : public Parser
{
private:
  std::ifstream	_file;
  regex_t	_regex;
public:
  Decrypt(const std::string& regex, const std::string& filename);
  ~Decrypt();
  std::vector<std::string>	decryptXor(const std::string& line);
  std::vector<std::string>	decryptCaesar(const std::string& line);
  std::vector<std::string>	decrypt();
};

#endif
