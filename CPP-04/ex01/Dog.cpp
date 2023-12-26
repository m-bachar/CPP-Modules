#include "Dog.hpp"

Dog::Dog()
{
	std::cout << GREEN << " * Dog " << RESET << "default constructor called !" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &obj)
{
	*this = obj;
}

Dog	&Dog::operator=(const Dog &obj)
{
	this->type = obj.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain();
	for (size_t i = 0; i < 100; i++)
		this->brain[i] = obj.brain[i];
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << PURPLE << " * " << getType() << RESET << " : Woof Woof !" << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << " * Dog " << RESET << "destructor called !" << std::endl;
	if (brain)
	delete brain;
}
