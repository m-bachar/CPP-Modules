#include "Zombie.hpp"

Zombie*		newZombie(std::string name) 
{
	Zombie	*zombieNew;

	zombieNew = new Zombie;
	zombieNew->zombieSetter(name);
	std::cout << zombieNew->zombieGetter() << ": BraiiiiiiinnnzzzZ...\n";
	return (zombieNew);
}
