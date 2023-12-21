#include "Animal.hpp"

Animal::Animal()
{
	std::cout << GREEN << "Animal " << RESET << "default constructor called !" << std::endl;
	type = "Animal";
}

Animal::Animal(const Animal &obj)
{
	this->type = obj.type;
}

Animal	&Animal::operator=(const Animal &obj)
{
	this->type = obj.type;
	return *this;
}

void	Animal::makeSound() const
{
	std::cout << PURPLE << type << RESET << " : Pkheeew !" << std::endl;
}

std::string	Animal::getType() const
{
	return type;
}

Animal::~Animal()
{
	std::cout << RED << "Animal " << RESET << "destructor called !" << std::endl;
}
