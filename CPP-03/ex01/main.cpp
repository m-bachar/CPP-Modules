#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap	scav("Hafozli9");
	ClapTrap	clap("Skerta7");

	scav.attack("Skerta7");
	clap.attack("Hafozli9");
	scav.beRepaired(50);
	clap.beRepaired(50);
	clap.takeDamage(50);
	scav.takeDamage(50);
	scav.guardGate();
}
