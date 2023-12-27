#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << GREEN << " * WrongCat " << RESET << "default constructor called !" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &obj)
{
	type = obj.type;
}

WrongCat	&WrongCat::operator=(const WrongCat &obj)
{
	type = obj.type;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << PURPLE << " * " << type << RESET << " : Mogheewwww ! (WrongCat) ... " << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << RED << " * WrongCat " << RESET << "destructor called !" << std::endl;
}