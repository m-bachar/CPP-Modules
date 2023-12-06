#include "Zombie.hpp"

int main()
{
    Zombie  *newzombie;

    std::cout << RED << "======================================\n" << RESET;
    newzombie = newZombie("PewPew");
    delete newzombie;
    std::cout << RED << "======================================\n" << RESET;
    randomChump("Bendawed");
}
