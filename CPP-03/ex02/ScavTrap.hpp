#pragma once

#include "ClapTrap.hpp"

class ScavTrap:public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &obj);
		void	attack(const std::string &target);
		void	guardGate();
		ScavTrap &operator=(const ScavTrap &obj);
		~ScavTrap();
};
