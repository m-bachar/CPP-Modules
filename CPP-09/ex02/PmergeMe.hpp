#pragma once

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

class PmergeMe
{
	private:
		// Vectors
		std::vector<int>					nbrs1_v;
		std::vector<int>					chain_v;
		std::vector<int>					pend_v;
		std::vector<int>					jacobsthal_v;
		std::vector<int>					combination_v;
		std::vector<std::pair<int,int> >	nbrs2_v;
		// Deques
		std::deque<int>					nbrs1_d;
		std::deque<int>					chain_d;
		std::deque<int>					pend_d;
		std::deque<int>					jacobsthal_d;
		std::deque<int>					combination_d;
		std::deque<std::pair<int,int> >	nbrs2_d;
		// Benito hihi
		int									struggler;
		bool								struggler_presence;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe	&operator=(const PmergeMe &obj);
		void		error(std::string errorMessage);
		void		swap(int &x, int &y);
		void		print(bool flag);
		size_t		getSize(std::string container);
		// Vector Methods
		int			parseInput_v(std::string av);
		void		checkVector();
		void		addPairs_v();
		void		sortPairs_v();
		void		stockInChainAndPend_v();
		void		jacobsThal_v();
		void		combinationGen_v();
		void		pushToChain_v();
		bool		find_v(std::vector<int>::iterator begin, std::vector<int>::iterator end, int occurence);
		// Deque Methods
		int			parseInput_d(std::string av);
		void		checkDeque();
		void		addPairs_d();
		void		sortPairs_d();
		void		stockInChainAndPend_d();
		void		jacobsThal_d();
		void		combinationGen_d();
		void		pushToChain_d();
		bool		find_d(std::deque<int>::iterator begin, std::deque<int>::iterator end, int occurence);
		~PmergeMe();
};
