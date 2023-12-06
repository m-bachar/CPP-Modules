#include "Harl.hpp"

void    Harl::debug(void)
{
    std::cout << GREEN << " * DEBUG   : " << RESET << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << GREEN << " * INFO    : " << RESET << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
   std::cout << GREEN << " * WARNING : " << RESET << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << GREEN << " * ERROR   : " << RESET << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    void    (Harl::*ptr[5])(void);

    ptr[0] = &Harl::debug;
    ptr[1] = &Harl::info;
    ptr[2] = &Harl::warning;
    ptr[3] = &Harl::error;
    (this->*ptr[std::atoi(level.c_str()) - 1])();
}
