#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weaponType):weapon(weaponType)
{
	this->name = name;
}

void	HumanA::attack()
{
	std::cout << GREEN << name << RESET << " attacks with their " << RED << weapon.getType() << RESET << std::endl;
}

HumanA::~HumanA()
{}
