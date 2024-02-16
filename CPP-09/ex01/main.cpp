#include "RPN.hpp"

int	main(int ac, char *av[])
{
	try {
		if (ac != 2)
		{
			std::cout << RED << " * Error : " << RESET << "invalid arguments count." << std::endl;
			return 1;
		}
		RPN	rpn(av[1]);
		if (rpn.parse_input())
			return 1;
		return 0;
	}
	catch (std::exception &e) {
		std::cout << RED << " * Error : " << RESET << e.what() << "." << std::endl;
	}
}
