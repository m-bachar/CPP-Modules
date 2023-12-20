#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap	scav("Hafozli9");
	ClapTrap	clap("Skerta7");
	FragTrap	frag("7at7out");

	scav.attack("Skerta7");
	clap.attack("Hafozli9");
	frag.attack("7at7out");
	scav.beRepaired(50);
	clap.beRepaired(50);
	frag.beRepaired(50);
	clap.takeDamage(500);
	scav.takeDamage(500);
	frag.takeDamage(500);
	scav.guardGate();
	frag.highFivesGuys();
}
