#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
	try {
		if (ac != 2)
		{
			std::cout << RED << " * Error : " << RESET << "invalid arguments count !" << std::endl;
			return 1;
		}
		BitcoinExchange btc;
		if (btc.readFile("data.csv", true))
			return 1;
		if (btc.readFile(av[1], false))
			return 1;
		return 0;
	}
	catch (std::exception &e) {
		std::cout << RED << " * Error : " << RESET << e.what() << std::endl;
	}
}
