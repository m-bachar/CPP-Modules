#pragma once

#include <iostream>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal &obj);
		Animal			&operator=(const Animal &obj);
		virtual	void	makeSound() const;
		std::string		getType() const;
		virtual ~Animal();
};