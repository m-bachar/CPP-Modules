#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << PURPLE << "ScavTrap " << GREEN << "Default " << RESET << "constructor called !" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << PURPLE << "ScavTrap " << GREEN << "Parametrized " << RESET << "constructor called !" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
	this->name = obj.name;
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &obj)
{
	this->name = obj.name;
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "ScavTrap " << PURPLE << name << RESET << " attacks " << PURPLE << target << RESET << ", causing " << RED << hitPoints << " points " << RESET << "of damage !" << std::endl;
		energyPoints--;
	}
	else
		std::cout << "ScavTrap " << PURPLE << name << RESET << " can not perform this action right now as he is " << RED << "dead" << RESET << " or" << ORANGE << " exhausted ." << RESET << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << PURPLE << name << RESET << " is now on " << GREEN << "guard mode !" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << PURPLE << "ScavTrap " << RED << "Destructor " << RESET << "called !" << std::endl;
}
