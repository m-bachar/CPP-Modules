#include "ClapTrap.hpp"

int main()
{
	ClapTrap	trap;

	trap.attack("Skerta7");
	trap.takeDamage(5);
	trap.beRepaired(100);
	trap.attack("DawDaw");
	trap.takeDamage(90);
	trap.beRepaired(50);
}
