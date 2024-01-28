#pragma once

#include <iostream>
#include <list>
#include <iterator>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

#define N 5

class Span // Span.cpp, 
{
	private:
		unsigned int N_;
	public:
		std::list<int> lst;
		Span();
		Span(unsigned int N__);
		Span(const Span &obj);
		Span	&operator=(const Span &obj);
		class TooManyElementsException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "too many elements.";
				}
		};
		void	addNumber(int nbr);
		class NoElementsFoundException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "no elements found or there is only one element in the container thus no span can be found.";
				}
		};
		int	shortestSpan();
		int	longestSpan();
		void	addNumbers(std::list<int> cont);
		~Span();
};
