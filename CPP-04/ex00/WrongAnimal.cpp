#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << GREEN << " * WrongAnimal " << RESET << "default constructor called !" << std::endl;
	type = "WrongAnimal";
}

std::string	WrongAnimal::getType()
{
	return type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	type = obj.type;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &obj)
{
	type = obj.type;
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << PURPLE << " * " << type << RESET << " : Moghoowwww ! (WrongAnimal) ... " << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << " * WrongAnimal " << RESET << "destructor called !" << std::endl;
	type = "WrongAnimal";
}
