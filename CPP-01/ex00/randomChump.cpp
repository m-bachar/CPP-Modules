#include "Zombie.hpp"

void		randomChump(std::string name)
{
	Zombie	zombienew;

	zombienew.zombieSetter(name);
	zombienew.announce();
}
