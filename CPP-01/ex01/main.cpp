#include "Zombie.hpp"

int main()
{
    Zombie  *zombiehorde1;
    Zombie  *zombiehorde2;
    Zombie  *zombiehorde3;

    zombiehorde1 = zombieHorde(5, "Dawdaw");
    delete[] zombiehorde1;
    zombiehorde2 = zombieHorde(5, "Dawdaw 1");
    delete[] zombiehorde2;
    zombiehorde3 = zombieHorde(5, "Dawdaw 2");
    delete[] zombiehorde3;
}
