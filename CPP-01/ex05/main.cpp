#include "Harl.hpp"

int main(int ac, char *av[])
{
    Harl harl;

    if (ac != 2)
    {
        std::cout << RED << " * Error : " << RESET << "invalid arguments number." << std::endl;
        return (1);
    }
    std::string level = av[1];
    if (std::atoi(level.c_str()) > 4 || std::atoi(level.c_str()) <= 0)
    {
        std::cout << RED << " * Error : " << RESET << "level should be between 1 and 4." << std::endl;
        return (1);
    }
    harl.complain(level);
    return 0;
}
