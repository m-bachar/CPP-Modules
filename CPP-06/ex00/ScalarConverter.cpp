#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << GREEN << " * ScalarConverter " << RESET << "default constructor called !" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	(void)obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	return *this;
}

void	char_parsing(std::string input)
{
	bool isdigit = true;
	for (size_t i = 0; i < input.length(); i++)
	{
		/*	Check if there is a digit after '.', eg : 42.1f = error	*/
		if (input[i] == '.')
		{
			int y = i + 1;
			while (input[y])
			{
				if (input[y] != 'f' && input[y] != '0')
				{
					std::cout << PURPLE << " * char   : " << RESET << "impossible" << std::endl;
					return;
				}
				y++;
			}
		}
		/*	Check if there is any character rather than digits, 'f' and '.'	*/
		if (!std::isdigit(input[i]) && input[i] != 'f' && input[i] != '.')
		{
			isdigit = false;
			break;
		}
	}
	if (isdigit == false)
	{
		std::cout << PURPLE << " * char   : " << RESET << "impossible" << std::endl;
		return;
	}
	/*	Check if the asci is printable	*/
	if (!std::isprint(std::atoi(input.c_str())))
		std::cout << PURPLE << " * char   : " << RESET << "non-displayable" << std::endl;
	else
		std::cout << PURPLE << " * char   : " << RESET << "\'" << static_cast<char>(std::atoi(input.c_str())) << "\'" << std::endl;
}

void	int_parsing(std::string input)
{
	bool		isdigit = true;
	int			dotscount = 0;
	std::string	pseudos[5] = {"-inff", "+inff", "-inf", "+inf", "nan"};

	for (int i = 0; i < 5; i++)
	{
		if (!input.compare(pseudos[i]))
		{
			std::cout << PURPLE << " * int    : " << RESET << "impossible" << std::endl;
			return;
		}
	}
	for (size_t i = 0; i < input.length(); i++)
		if (input[i] == '.')
			dotscount++;
	if (dotscount > 1)
	{
		std::cout << PURPLE << " * int    : " << RESET << "impossible" << std::endl;
		return;
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]) && input[0] != '+' && input[0] != '-' && input[input.length() - 1] != 'f' && input[i] != '.')
		{
			isdigit = false;
			break;
		}
	}
	if (isdigit == false)
	{
		std::cout << PURPLE << " * int    : " << RESET << "impossible" << std::endl;
		return;
	}
	std::stringstream overflow;
	overflow << input;
	int x;
	if (!(overflow >> x))
		std::cout << PURPLE << " * int    : " << RESET << "overflown" << std::endl;
	else
		std::cout << PURPLE << " * int    : " << RESET << static_cast<int>(std::atoi(input.c_str())) << std::endl;
}

void	float_parsing(std::string input)
{
	bool	isdigit = true;
	int		dotscount = 0;
	std::string	pseudos[2] = {"-inff", "+inff"}; // Pseudos 00
	std::string	pseudos_[3] = {"-inf", "+inf", "nan"}; // Pseudos 01

	/*	Check and print Pseudos 00	*/
	for (int i = 0; i < 2; i++)
	{
		if (!input.compare(pseudos[i]))
		{
			std::cout << PURPLE << " * float : " << RESET << pseudos[i] << std::endl;
			return;
		}
	}
	/*	Check and print Pseudos 01	*/
	for (int i = 0; i < 3; i++)
	{
		if (!input.compare(pseudos_[i]))
		{
			std::cout << PURPLE << " * float  : " << RESET << pseudos_[i] << 'f' << std::endl;
			return;
		}
	}
	/*	Check float syntax (dots and (+ / -) count)	*/
	for (size_t i = 0; i < input.length(); i++)
		if (input[i] == '.')
			dotscount++;
	if (dotscount > 1)
	{
		std::cout << PURPLE << " * float  : " << RESET << "impossible" << std::endl;
		return;
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]) && input[0] != '+' && input[0] != '-' && input[input.length() - 1] != 'f' && input[i] != '.')
		{
			isdigit = false;
			break;
		}
	}
	/*	Remove float mark from input	*/
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == 'f')
			input = input.substr(0, i);
	}
	/*	Check if number overflowed	*/
	std::stringstream overflow;
	overflow << input;
	float x;
	if (!(overflow >> x))
	{
		std::cout << PURPLE << " * float  : " << RESET << "overflown" << std::endl;
		return;
	}
	/*	Check if input has a different character	*/
	if (isdigit == false)
	{
		std::cout << PURPLE << " * float  : " << RESET << "impossible" << std::endl;
		return;
	}
	else
	{
		if (dotscount == 0)
			std::cout << PURPLE << " * float  : " << RESET << static_cast<float>(std::atof(input.c_str())) << ".0f" << std::endl;
		else
			std::cout << PURPLE << " * float  : " << RESET << static_cast<float>(std::atof(input.c_str())) << 'f' << std::endl;
	}
}

void	double_parsing(std::string input)
{
	bool	isdigit = true;
	int		dotscount = 0;
	std::string	pseudos[5] = {"-inff", "+inff", "-inf", "+inf", "nan"};

	for (int i = 0; i < 5; i++)
	{
		if (!input.compare(pseudos[i]))
		{
			std::cout << PURPLE << " * double : " << RESET << pseudos[i] << std::endl;
			return;
		}
	}
	for (size_t i = 0; i < input.length(); i++)
		if (input[i] == '.')
			dotscount++;
	if (dotscount > 1)
	{
		std::cout << PURPLE << " * double : " << RESET << "impossible" << std::endl;
		return;
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]) && input[0] != '+' && input[0] != '-' && input[input.length() - 1] != 'f' && input[i] != '.')
		{
			isdigit = false;
			break;
		}
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == 'f')
			input = input.substr(0, i);
	}
	std::stringstream overflow;
	overflow << input;
	double	x;
	if (!(overflow >> x))
	{
		std::cout << PURPLE << " * double : " << RESET << "overflown" << std::endl;
		return;
	}
	if (isdigit == false)
	{
		std::cout << PURPLE << " * double : " << RESET << "impossible" << std::endl;
		return;
	}
	else
	{
		if (dotscount == 0)
			std::cout << PURPLE << " * double : " << RESET << static_cast<double>(std::atof(input.c_str())) << ".0" << std::endl;
		else
			std::cout << PURPLE << " * double : " << RESET << static_cast<double>(std::atof(input.c_str())) << std::endl;
	}
}

void	ScalarConverter::convert(std::string input)
{
	char_parsing(input);
	int_parsing(input);
	float_parsing(input);
	double_parsing(input);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << RED << " * ScalarConverter " << RESET << "destructor called !" << std::endl;
}
