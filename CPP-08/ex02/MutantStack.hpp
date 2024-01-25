#pragma once

#include <iostream>
#include <stack>
#include <list>
#include <iterator>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

template <typename T>
class MutantStack : public std::stack<T, std::list<T> >
{
	public:
		typedef typename std::list<T>::iterator iterator;
		iterator	begin()
		{
			return this->c.begin();
		}
		iterator	end()
		{
			return this->c.end();
		}
		MutantStack()
		{
			std::cout << GREEN << " * MutantStack " << RESET << "default constructor called !" << std::endl;
		}
		MutantStack(const MutantStack &obj)
		{
			*this = obj;
		}
		MutantStack	&operator=(const MutantStack &obj)
		{
			this->c = obj.c;
			return *this;
		}
		~MutantStack()
		{
			std::cout << RED << " * MutantStack " << RESET << "destructor called !" << std::endl;
		}
};
