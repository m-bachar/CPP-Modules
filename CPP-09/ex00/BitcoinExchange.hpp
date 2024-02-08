#pragma once

#include <iostream>
#include <map>
#include <iterator>
#include <fstream>
#include <algorithm>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

class BitcoinExchange
{
	private:
		std::map<std::string, std::string>	input;
		std::map<std::string, std::string>	db;
		std::string							line;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange	&operator=(const BitcoinExchange &obj);
		int		readFile(std::string filename);
		void	parseLine(std::string line);
		void	parseDateValue(std::string date, std::string value, int flag);
		~BitcoinExchange();
};