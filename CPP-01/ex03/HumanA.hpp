#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"

class HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;
	public:
		HumanA(std::string name, Weapon &weaponType);
		void	attack(void);
		~HumanA();
};

#endif
