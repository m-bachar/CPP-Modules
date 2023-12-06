#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

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
	void		zombieSetter(std::string name);
	std::string	zombieGetter(void);
	void		announce(void);
	~Zombie();
};

Zombie*     zombieHorde(int N, std::string name);

#endif
