#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << RED << " * Error : " << RESET << "invalid arguments count !" << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	if (btc.readFile(av[1]))
		return 1;
	return 0;
}
