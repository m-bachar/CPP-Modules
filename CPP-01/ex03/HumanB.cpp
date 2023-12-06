#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    weapon = NULL;    
}

void    HumanB::attack(void)
{
    if (weapon != NULL)
        std::cout << GREEN << name << RESET << " attacks with their " << RED << weapon->getType() << RESET << std::endl;
}

void    HumanB::setWeapon(Weapon &weaponType)
{
    this->weapon = &weaponType;
}

HumanB::~HumanB()
{}
