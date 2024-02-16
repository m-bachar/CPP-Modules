#pragma once

#include <iostream>
#include <stack>
#include <iterator>
#include <algorithm>
#include <deque>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe	&operator=(const PmergeMe &obj);
		~PmergeMe();
};
