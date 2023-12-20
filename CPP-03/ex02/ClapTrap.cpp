#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << PURPLE << "ClapTrap " << GREEN << "Default " << RESET << "constructor called !" << std::endl;
	this->name = "Benito";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << PURPLE << "ClapTrap " << GREEN << "Parametrized " << RESET << "constructor called !" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	this->name = obj.name;
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &obj)
{
	this->name = obj.name;
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
	return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "ClapTrap " << PURPLE << name << RESET << " attacks " << PURPLE << target << RESET << ", causing " << RED << hitPoints << " points " << RESET << "of damage !" << std::endl;
		energyPoints--;
	}
	else
		std::cout << "ClapTrap " << PURPLE << name << RESET << " can not perform this action right now as he is " << RED << "dead" << RESET << " or" << ORANGE << " exhausted ." << RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if ((int)amount < 0)
	{
		std::cout << RED << "Error : " << RESET << "amount must be a positive number." << std::endl;
		exit (1);
	}
	hitPoints -= amount;
	if (hitPoints > 0)
		std::cout << PURPLE << name << RESET << " has taken " << RED << amount << " damage points !" << RESET << std::endl;
	else
		std::cout << PURPLE << name << RESET << " has taken " << RED << amount << " damage points " << RESET << "and " << RED << "died !" << RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if ((int)amount < 0)
	{
		std::cout << RED << "Error : " << RESET << "amount must be a positive number." << std::endl;
		exit (1);
	}
	if (hitPoints > 0 && energyPoints > 0)
	{
		hitPoints += amount;
		energyPoints--;
		std::cout << PURPLE << name << RESET << " has taken a painkiller and increased his health by " << GREEN << amount << " hit points !" << RESET << std::endl;
	}
	else
		std::cout << PURPLE << name << RESET << " can not perform this action right now as he is " << RED << "dead" << RESET << " or" << ORANGE << " exhausted ." << RESET << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << PURPLE << "ClapTrap " << RED << "Destructor " << RESET << "called !" << std::endl;
}
