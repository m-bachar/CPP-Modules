#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie  *newzombie;
    
    if (N <= 0)
        return (NULL);
    newzombie = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        newzombie[i].zombieSetter(name);
        newzombie[i].announce();
    }
    return (newzombie);
}
