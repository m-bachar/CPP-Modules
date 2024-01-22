#pragma once

#include <iostream>
#include <sstream>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

class ScalarConverter
{
	private:
		ScalarConverter();
	public:
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter &operator=(const ScalarConverter &obj);
		static void	convert(std::string input);
		~ScalarConverter();
};

void char_parsing(std::string input);
void int_parsing(std::string input);
void float_parsing(std::string input);
void double_parsing(std::string input);