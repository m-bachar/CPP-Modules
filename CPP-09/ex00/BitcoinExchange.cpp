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

	if (!file.is_open()) {
		std::cout << RED << " * Error : " << RESET << "unable to open or locate the file." << std::endl;
		return 1;
	}
	while (file.get(c)) {
		if (c == '\n') {
			parseLine(line);
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
	bool	errors_flag = false;
	if (flag == 0) {
		if (date != "date " || value != "| value") {
			std::cout << RED << " * Error : " << RESET << "date and value must be as follow (date | value)" << std::endl;
			errors_flag = true;
		}
	}
	else {
		if (date < "2009-01-02" || date > "2022-03-29") {
			std::cout << RED << " * Error : " << RESET << "date " << date << "is out of range" << std::endl;
			errors_flag = true;
		}
		std::string	value_sub = value.substr(value.find_first_of(' ') + 1, value.find_last_of('\n'));
		int	dot_counter = 0;
		for (size_t i = 0; i < value_sub.length(); i++) {
			if (value_sub[0] == '-' || value_sub[0] == '+')
				i++;
			if (value_sub[i] == '.')
				dot_counter++;
			if ((!std::isdigit(value_sub[i]) && value_sub[i] != '.') || dot_counter > 1) {
				std::cout << RED << " * Error : " << RESET << value_sub << " not a digit" << std::endl;
				errors_flag = true;
				break;
			}
		}
		if (std::atof(value_sub.c_str()) < 0 || std::atof(value_sub.c_str()) > 1000) {
			std::cout << RED << " * Error : " << RESET << value_sub << " must be between (0 - 1000)" << std::endl;
			errors_flag = true;
		}
		// if (errors_flag) { // Insert db and input in map and dreb chi f chi htel eand molchi :D

		// }
	}
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << RED << " * BitcoinExchange " << RESET << "destructor called !" << std::endl;
}
