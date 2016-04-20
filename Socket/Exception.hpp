//
// Exception.hpp for  in /home/cloquet/Documents/cpp/cpp_plazza
//
// Made by Cloquet
// Login   <cloquet@epitech.net>
//
// Started on  Mon Apr 11 15:01:30 2016 Cloquet
// Last update Mon Apr 11 15:01:31 2016 Cloquet
//

#ifndef                EXCEPTION_HPP
# define        EXCEPTION_HPP

# include	<exception>
# include	<iostream>
# include	<string>

class exception : public std::exception
{
 public:
  exception(const std::string &message);

  ~exception() throw();

  const char *what() const throw();

 private:
  std::string _msg;
};

#endif /* EXCEPTION_HPP */
