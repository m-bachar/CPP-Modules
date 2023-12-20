#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << PURPLE << "FragTrap " << GREEN << "Default " << RESET << "constructor called !" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << PURPLE << "FragTrap " << GREEN << "Parametrized " << RESET << "constructor called !" << std::endl;
	this->name = name;
}

FragTrap::FragTrap(const FragTrap &obj)
{
	this->name = obj.name;
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
}

FragTrap	&FragTrap::operator=(const FragTrap &obj)
{
	this->name = obj.name;
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << PURPLE << name << RESET << "wants to give everyone a warm " << GREEN <<  "high five !" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << PURPLE << "FragTrap " << RED << "Destructor " << RESET << "called !" << std::endl;
}
