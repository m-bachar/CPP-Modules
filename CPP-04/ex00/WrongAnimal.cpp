#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << GREEN << " * WrongAnimal " << RESET << "default constructor called !" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << " * WrongAnimal " << RESET << "destructor called !" << std::endl;
	type = "WrongAnimal";
}
