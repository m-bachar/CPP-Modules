#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GREEN << " * Brain " << RESET << "default constructor called !" << std::endl;
}

Brain::Brain(const Brain &obj)
{
	for (size_t i = 0; i < std::strlen(ideas->c_str()); i++)
		this->ideas[i] = obj.ideas[i];	
}

Brain	&Brain::operator=(const Brain &obj)
{
	for (size_t i = 0; i < std::strlen(ideas->c_str()); i++)
		this->ideas[i] = obj.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << RED << " * Brain " << RESET << "destructor called !" << std::endl;
}
