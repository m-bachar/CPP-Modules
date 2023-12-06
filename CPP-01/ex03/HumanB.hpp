#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"

class HumanB
{
    private:
        std::string name;
        Weapon      *weapon;
    public:
        HumanB();
        HumanB(std::string name);
        void    attack(void);
        void    setWeapon(Weapon &weaponType);
        ~HumanB();
};

#endif
