#pragma once

#include "ClapTrap.hpp"

class FragTrap:public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &obj);
		FragTrap &operator=(const FragTrap &obj);
		void	highFivesGuys(void);
		~FragTrap();
};
