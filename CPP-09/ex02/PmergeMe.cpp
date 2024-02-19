#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	struggler_presence = false;
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	*this = obj;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &obj)
{
	nbrs1 = obj.nbrs1;
	chain = obj.chain;
	pend = obj.pend;
	jacobsthal = obj.jacobsthal;
	sequence = obj.sequence;
	nbrs2 = obj.nbrs2;
	struggler = obj.struggler;
	struggler_presence = obj.struggler_presence;
	return *this;
}

void	PmergeMe::error(std::string errorMessage)
{
	std::cout << RED << " * Error : " << RESET << errorMessage << std::endl;
}

// Some utilities here won't hurt right? :D
void	PmergeMe::swap(int &x, int &y)
{
	int	tmp;

	tmp = x;
	x = y;
	y = tmp;
}

bool	PmergeMe::findd(std::vector<int>::iterator begin, std::vector<int>::iterator end, int occurence)
{
	while (begin != end) {
		if (*begin == occurence)
			return false;
		begin++;
	}
	return true;
}

// Step 1 : Parse the input
int	PmergeMe::parseInput(std::string av)
{
	int	i = 0;
	while (av[i]) {
		if (!std::isdigit(av[i]) && av[i] != '-' && av[i] != '+') {
			error("arguments must be numbers only.");
			return 1;
		}
		i++;
	}
	std::stringstream overflow;
	overflow << av;
	int x;
	if (!(overflow >> x)) {
		error("number is not a integer.");
		return 1;
	}
	if (std::atoi(av.c_str()) < 0) {
		error("number must be positive.");
		return 1;
	}
	nbrs1.push_back(std::atoi(av.c_str()));
	return 0;
}

// Step 2 : Check if container's size if not pair ==> pop the struggler
void	PmergeMe::checkVector()
{
	if (nbrs1.size() % 2 != 0) {
		struggler = nbrs1.back();
		nbrs1.pop_back();
		struggler_presence = true;
	}
}

// Step 3 : Divide the container into pairs of numbers and sort it's elements
void	PmergeMe::addPairs()
{
	size_t i = 0;
	size_t j = 1;

	while (j < nbrs1.size()) {
		nbrs2.push_back(std::make_pair(nbrs1[i], nbrs1[j]));
		i += 2;
		j += 2;
	}
	// Swap pairs
	std::vector<std::pair<int, int> >::iterator it = nbrs2.begin();
	while (it != nbrs2.end()) {
		if (it->first < it->second)
			swap(it->first, it->second);
		it++;
	}
}

// Step 4 : Sort the pairs based on the first element of each pair
void PmergeMe::sortPairs() 
{
	for (size_t i = 0; i < nbrs2.size(); ++i) {
		for (size_t j = i + 1; j < nbrs2.size(); ++j) {
			if (nbrs2[i].first > nbrs2[j].first) {
				swap(nbrs2[i].first, nbrs2[j].first);
				swap(nbrs2[i].second, nbrs2[j].second);
			}
		}
	}
}

// Step 5 : Stock first elements in main chain and second elements in pend chain
void	PmergeMe::stockInChainAndPend()
{
	std::vector<std::pair<int, int> >::iterator	it = nbrs2.begin();

	while (it != nbrs2.end()) {
		chain.push_back(it->first);
		pend.push_back(it->second);
		it++;
	}
	// Push first element in Pend to the Main Chain
	std::vector<int>::iterator	it_ = pend.begin();
	chain.insert(chain.begin(), *it_);
}

// Step 6 : The almighty Jaconbs Thal algorithm
void	PmergeMe::jacobsThal()
{
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	jacobsthal.push_back(1);

	if (jacobsthal.size() == 0) {
		error("container is empty.");
		return ;
	}
	size_t i;
	size_t	new_nbr = 0;
	while (new_nbr <= pend.size()) {
		i = jacobsthal.size();
		new_nbr = (jacobsthal[i - 1] * 1) + (jacobsthal[i - 2] * 2);
		jacobsthal.push_back(new_nbr);
	}
}

// Step 7 : Generating the sequence (It's a pain in the ass :( )
void	PmergeMe::sequenceGen()
{
	for (std::vector<int>::iterator it = jacobsthal.begin() + 3; it != jacobsthal.end(); it++) {
		size_t new_nbr = *it;
		while (findd(jacobsthal.begin(), it, new_nbr)) {
			if (new_nbr > pend.size()) {
				new_nbr--;
				continue;
			}
			else
				sequence.push_back(new_nbr);
			new_nbr--;
		}
	}
}

// Step 8 : Push elements from pend to chain using merge sort
void	PmergeMe::pushToChain()
{
	std::vector<int>::iterator	j = sequence.begin();

	while (j != sequence.end()) {
		int index = *j - 1;
		if (pend[index]) {
			std::vector<int>::iterator it = std::lower_bound(chain.begin(), chain.end(), pend[index]);
			if (it != chain.end())
				chain.insert(it, pend[index]);
		}
		j++;
	}
	if (struggler_presence == true) {
		std::vector<int>::iterator it = std::lower_bound(chain.begin(), chain.end(), struggler);
			chain.insert(it, struggler);
	}
}

PmergeMe::~PmergeMe()
{}
