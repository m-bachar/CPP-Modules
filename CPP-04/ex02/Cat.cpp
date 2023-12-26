#include "Cat.hpp"

Cat::Cat()
{
	std::cout << GREEN << " * Cat " << RESET << "default constructor called !" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &obj)
{
	*this = obj;
}

Cat	&Cat::operator=(const Cat &obj)
{
	this->type = obj.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain();
	for (size_t i = 0; i < 100; i++)
		this->brain[i] = obj.brain[i];
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << PURPLE << " * " << getType() << RESET << " : Meeeeoooowww !" << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << " * Cat " << RESET << "destructor called !" << std::endl;
	if (brain)
	delete brain;
}
