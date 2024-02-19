#pragma once

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <ctime>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

class PmergeMe
{
	public: // change it to private !!
		// Vectors
		std::vector<int>					nbrs1;
		std::vector<int>					chain;
		std::vector<int>					pend;
		std::vector<int>					jacobsthal;
		std::vector<int>					sequence;
		std::vector<std::pair<int,int> >	nbrs2;
		// Deques
		int									struggler;
		bool								struggler_presence;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe	&operator=(const PmergeMe &obj);
		void		error(std::string errorMessage);
		int			parseInput(std::string av);
		void		checkVector();
		void		addPairs();
		void		sortPairs();
		void		swap(int &x, int &y);
		void		stockInChainAndPend();
		void		jacobsThal();
		void		sequenceGen();
		void		pushToChain();
		bool		findd(std::vector<int>::iterator begin, std::vector<int>::iterator end, int occurence);
		~PmergeMe();
};
