#pragma once

#include <iostream>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

class WrongCat;

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &obj);
		WrongAnimal	&operator=(const WrongAnimal &obj);
		WrongAnimal	getType();
		virtual	void	makeSound();
		virtual	~WrongAnimal();
};
