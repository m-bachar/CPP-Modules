#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	db = obj.db;
	date = obj.date;
	value = obj.value;
	year = obj.year;
	month = obj.month;
	day = obj.day;
	return *this;
}

void	BitcoinExchange::error(std::string errorMessage)
{
	std::cout << RED << " * Error : " << RESET << errorMessage << std::endl;
}

int	BitcoinExchange::readFile(std::string filename, bool database)
{
	std::ifstream	myFile(filename.c_str());
	std::string		line;

	if (!myFile)
		error("unable to locate or open file.");
	// Check if file is empty
	while (std::getline(myFile, line)) {
		if (parseLine(line, database))
			return 1;
	}
	return 0;
}

int	BitcoinExchange::countSpace(std::string line)
{
	int	counter = 0;

	for (size_t i = 0; i < line.length(); i++)
	{
		if (line[i] == ' ')
			counter++;
	}
	return counter;
}

int	BitcoinExchange::checkDigits(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return 1;
	return 0;
}

int	BitcoinExchange::parseDate(std::string date)
{
	size_t first_dash = date.find('-');
	size_t second_dash = date.find('-');
	if (first_dash == std::string::npos || second_dash == std::string::npos) {
		error("date syntax must be as follow (yyyy-mm-dd).");
		return 1;
	}
	year = date.substr(0, first_dash);
	month = date.substr(first_dash + 1, second_dash - 2);
	day = date.substr(date.find_last_of('-') + 1, date.length() - date.find_last_of('-'));
	if (checkDigits(year) || checkDigits(month) || checkDigits(day)) {
		error("year, month and day must have only digits.");
		return 1;
	}
	if (date < "2009-01-02") { // To be continued ...
		error("date is out of range.");
		return 1;
	}
	if (std::atoi(month.c_str()) > 12 || std::atoi(month.c_str()) <= 0 || std::atoi(day.c_str()) > 30 || std::atoi(day.c_str()) <= 0) {
		error("month must be between (1 - 12) and day must be between (1 - 30).");
		return 1;
	}
	return 0;
}

int	BitcoinExchange::parseValue(std::string value)
{
	int	dots_counter = 0;
	// Counting dots in the value
	for (size_t i = 0; i < value.length(); i++)
		if (value[i] == '.')
			dots_counter++;
	if (dots_counter > 1) {
		error("number of (.) must be only one for a float number.");
		return 1;
	}
	// Checking float syntax
	for (size_t i = 0; i < value.length(); i++) {
		if (value[i] == '.' && (!std::isdigit(value[i - 1]) || !std::isdigit(value[i + 1]))) {
			error("float syntax should be as follow (x.y)");
			return 1;
		}
	}
	// Checking if value has a different character other than digits
	for (size_t i = 1; i < value.length(); i++)
	{
		if (value[0] != '+' && value[0] != '-' && !std::isdigit(value[0])) {
			error("value should only contain digits.");
			return 1;
		}
		if (!std::isdigit(value[i]) && value[i] != '.') {
			error("value should only contain digits.");
			return 1;
		}
	}
	// Check if value is < 0 or > 1000
	if (std::atof(value.c_str()) < 0 || std::atof(value.c_str()) > 1000) {
		error("value must be between (0 - 1000)");
		return 1;
	}
	return 0;
}

int	BitcoinExchange::parseLine(std::string line, bool database)
{
	static int flag = 0;
	// database == false ==> Parsing input file 
	if (database == false) {
		int	space_count = countSpace(line);
		size_t pipe_pos = line.find(" | ");
		if (pipe_pos == std::string::npos || space_count != 2) {
			error("syntax should be as follow (date | value).");
			return 0;
		}
		date = line.substr(0, pipe_pos);
		value = line.substr(pipe_pos + 3, line.length() - pipe_pos);
		// flag == 0 ==> Parsing first line in the input file
		if (flag == 0) {
			if (date != "date" || value != "value") {
				error("syntax should be as follow (date | value).");
				return 1;
			}
			flag = 1;
			return 0;
		}
		// flag != 0 ==> Parsing other lines in the input file
		if (flag) {
			if (parseDate(date) || parseValue(value))
				return 0;
		}
		std::multimap<std::string, float>::iterator	head = db.begin();
		std::multimap<std::string, float>::iterator	it = db.lower_bound(date);
		if (head->first < it->first)
			it--;
		std::cout << GREEN << " * " << date << RESET << " ==> " << value << " * " << it->second << " = " << std::atof(value.c_str()) * it->second << std::endl;
		
	}
	// database == true ==> Parsing .csv file
	if (database == true) {
		size_t del_pos = line.find(",");
		if (del_pos == std::string::npos) {
			error("syntax should be as follow (date,value).");
			return 0;
		}
		date = line.substr(0, del_pos);
		value = line.substr(del_pos + 1, line.length() - del_pos);
		db.insert(std::make_pair(date, std::atof(value.c_str())));
	}
	return 0;
}

BitcoinExchange::~BitcoinExchange()
{}
