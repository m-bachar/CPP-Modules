#include "harlFilter.hpp"

void    harlFilter::debug(void)
{
    std::cout << GREEN << " * DEBUG   : " << RESET << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    harlFilter::info(void)
{
    std::cout << GREEN << " * INFO    : " << RESET << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    harlFilter::warning(void)
{
   std::cout << GREEN << " * WARNING : " << RESET << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    harlFilter::error(void)
{
    std::cout << GREEN << " * ERROR   : " << RESET << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void harlFilter::complain(std::string level)
{
    switch (std::atoi(level.c_str()))
    {
        case 1:
            debug();
        case 2:
            info();
        case 3:
            warning();
        case 4:
            error();
            break;
        default:
            std::cout << RED << "Error : " << RESET << "level must be between 1 and 4." << std::endl;
            return;
    }
}
