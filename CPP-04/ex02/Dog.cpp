#include "Dog.hpp"

Dog::Dog()
{
	std::cout << GREEN << " * Dog " << RESET << "default constructor called !" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &obj)
{
	this->type = obj.type;
	this->brain = new Brain();
}

Dog	&Dog::operator=(const Dog &obj)
{
	this->type = obj.type;
	this->brain = new Brain();
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << PURPLE << " * " << getType() << RESET << " : Woof Woof !" << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << " * Dog " << RESET << "destructor called !" << std::endl;
	delete brain;
}
