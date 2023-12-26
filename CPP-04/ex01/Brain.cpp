#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GREEN << " * Brain " << RESET << "default constructor called !" << std::endl;
	for (int i = 0 ; i < 100 ; i++)
        this->ideas[i] = "Dawdaaaww";
}

Brain::Brain(const Brain &obj)
{
    *this = obj;
}

Brain	&Brain::operator=(const Brain &obj)
{
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << RED << " * Brain " << RESET << "destructor called !" << std::endl;
}
