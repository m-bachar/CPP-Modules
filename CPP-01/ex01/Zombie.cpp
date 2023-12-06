#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << GREEN << "** Constructor : " << RESET << "A zombie " << ORANGE << zombieGetter() << RESET << "has spawned !\n";
}

Zombie::~Zombie()
{
	std::cout << RED << "** Destructor  : " << RESET << "Zombie " << ORANGE << zombieGetter() << RESET << " has been killed !\n";
}

void	Zombie::zombieSetter(std::string name)
{
	this->name = name;
}

std::string	Zombie::zombieGetter(void)
{
	return (name);
}

void	Zombie::announce(void)
{
	std::cout << zombieGetter() << ": BraiiiiiiinnnzzzZ...\n";
}
