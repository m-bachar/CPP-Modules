#pragma once

#include <iostream>
#include <list>
#include <iterator>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

#define N 10000

class Span
{
	private:
		unsigned int N_;
	public:
		std::list<int> lst;
		Span()
		{
			std::cout << GREEN << " * Span " << RESET << "default constructor called !" << std::endl;
			N_ = N;
		}
		Span(unsigned int N__)
		{
			std::cout << GREEN << " * Span " << RESET << "parametrized constructor called !" << std::endl;
			N_ = N__;
		}
		Span(const Span &obj)
		{
			*this = obj;
		}
		Span	&operator=(const Span &obj)
		{
			N_ = obj.N_;
			lst = obj.lst;
			return *this;
		}
		class TooManyElementsException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "too many elements.";
				}
		};
		void	addNumber(int nbr)
		{
			std::list<int>::iterator it;
			int	i = 0;
			for (it = lst.begin(); it != lst.end(); it++)
				i++;
			if (i >= (int)N_)
				throw TooManyElementsException();
			lst.push_back(nbr);
		}
		class NoElementsFoundException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "no elements found or there is only one element in the container thus no span can be found.";
				}
		};
		int	shortestSpan()
		{
			if (lst.empty() || lst.size() == 1)
				throw NoElementsFoundException();

			lst.sort();
			return lst.front() - 1;
		}
		int	longestSpan()
		{
			if (lst.empty() || lst.size() == 1)
				throw NoElementsFoundException();

			lst.sort();
			return lst.back() - lst.front();
		}
		void	burn_the_cpu_or_u_gay()
		{
			srand(time(NULL));
			for (int i = 0; i < N; i++)
			{
				int nbr = rand();
				addNumber(nbr);
			}
		}
		~Span()
		{
			std::cout << RED << " * Span " << RESET << "destructor called !" << std::endl;
		}
};
