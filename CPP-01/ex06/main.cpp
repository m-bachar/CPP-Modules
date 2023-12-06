#include "harlFilter.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cout << RED << "Error : " << RESET << "invalid arguments number." << std::endl;
        return (1);
    }
    harlFilter        harlfilter;
    std::string level;
    level = av[1];
    harlfilter.complain(level);
}
