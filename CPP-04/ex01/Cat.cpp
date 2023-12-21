#include "Cat.hpp"

Cat::Cat()
{
	std::cout << GREEN << "Cat " << RESET << "default constructor called !" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &obj)
{
	this->type = obj.type;
}

Cat	&Cat::operator=(const Cat &obj)
{
	this->type = obj.type;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << PURPLE << getType() << RESET << " : Meeeeoooowww !" << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat " << RESET << "destructor called !" << std::endl;
}
