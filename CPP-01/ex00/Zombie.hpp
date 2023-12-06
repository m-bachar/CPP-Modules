#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

#define RESET     "\x1b[0m"
#define GREEN     "\x1b[1;32m"
#define RED       "\x1b[1;31m"
#define ORANGE    "\x1b[1;34m"

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		void		zombieSetter(std::string	name);
		std::string	zombieGetter(void);
		void		announce(void);
		~Zombie();
};

Zombie*		newZombie(std::string	name);
void		randomChump(std::string	name);

#endif
