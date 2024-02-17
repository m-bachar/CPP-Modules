#pragma once

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

class PmergeMe
{
	public: // change it to private !!
		std::vector<int>	nbrs1;
		int					struggler;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe	&operator=(const PmergeMe &obj);
		void		error(std::string errorMessage);
		int			parseInput(std::string av);
		void		checkVector();
		~PmergeMe();
};
