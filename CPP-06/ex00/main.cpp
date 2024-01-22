#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << RED << " * Error : " << RESET << "invalid arguments count !" << std::endl;
		return 1;
	}
	std::string	arg(av[1]);
	ScalarConverter::convert(arg);
	return 0;
}
