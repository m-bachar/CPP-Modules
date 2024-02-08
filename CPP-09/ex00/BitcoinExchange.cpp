#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << GREEN << " * BitcoinExchange " << RESET << "default constructor called !" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	line = obj.line;
	return *this;
}

int	BitcoinExchange::readFile(std::string filename)
{
	std::ifstream file(filename);
	char	c;
	if (!file.is_open())
	{
		std::cout << RED << " * Error : " << RESET << "unable to open or locate the file." << std::endl;
		return 1;
	}
	while (file.get(c))
	{
		if (c == '\n')
		{
			std::cout << ORANGE << " * Line = " << RESET << line << std::endl;
			line.clear();
		}
		else
			line += c;
	}
	file.close();
	return 0;
}

void	BitcoinExchange::parseLine(std::string line)
{
	int	i = 0;
	static int flag = 0;
	std::string	date = line.substr(i, line.find('|'));
	i = line.find('|');
	std::string	value = line.substr(i, line.find('\n'));
	parseDateValue(date, value, flag);
	flag++;
}

void	BitcoinExchange::parseDateValue(std::string date, std::string value, int flag)
{
	if (flag == 0)
	{
		std::cout << ORANGE << " * Date = " << RESET << date << std::endl;
		std::cout << ORANGE << " * Value = " << RESET << value << std::endl;
		if (!std::strcmp(date.c_str(), "date") || !std::strcmp(value.c_str(), " | value"))
			std::cout << RED << " * Error : " << RESET << "date and value must be as follow (date | value)" << std::endl;
	}
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << RED << " * BitcoinExchange " << RESET << "destructor called !" << std::endl;
}
