#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <iterator>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

# define N 10

class OccurenceNotFoundException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "occurence not found in the container.";
		}
};

template <typename T>
int	easyfind(T x, int y)
{
    std::vector<char>::iterator it = std::find(std::begin(x), std::end(x), y);
 
    if (it != std::end(x))
		return *it;
	else
		throw OccurenceNotFoundException();
}
