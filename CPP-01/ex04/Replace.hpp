#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"

std::string	readFile(std::string fileName);
std::string	search_and_replace(std::string fileContent, std::string s1, std::string s2);
void		error(std::string errorMsg);

#endif
