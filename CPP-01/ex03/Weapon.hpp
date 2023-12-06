#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon(std::string type);
		const std::string&	getType(void);
		void				setType(std::string type);
		~Weapon();
};

#endif
