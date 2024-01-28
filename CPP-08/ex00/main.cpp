#include "easyfind.hpp"

int main()
{
	std::vector<char> vectora;
	std::vector<char>::iterator it;

	for (char i = 97; i < 107; i++)
		vectora.push_back(i);
	std::cout << GREEN << " * Vector : " << RESET;
	for (it = vectora.begin(); it < vectora.end(); it++)
		std::cout << static_cast<char>(*it) << " ";
	std::cout << std::endl;
	try
	{
		std::cout << static_cast<char>(::easyfind(vectora, 102)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << " * Error : " << RESET << e.what() << std::endl;
	}
}
