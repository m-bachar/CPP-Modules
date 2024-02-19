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
	// Vector
	nbrs1_v = obj.nbrs1_v;
	chain_v = obj.chain_v;
	pend_v = obj.pend_v;
	jacobsthal_v = obj.jacobsthal_v;
	sequence_v = obj.sequence_v;
	nbrs2_v = obj.nbrs2_v;

	// Deque
	nbrs1_d = obj.nbrs1_d;
	chain_d = obj.chain_d;
	pend_d = obj.pend_d;
	jacobsthal_d = obj.jacobsthal_d;
	sequence_d = obj.sequence_d;
	nbrs2_d = obj.nbrs2_d;

	// Benito hihi
	struggler = obj.struggler;
	struggler_presence = obj.struggler_presence;
	return *this;
}

// Some utilities here won't hurt right? :D
void	PmergeMe::error(std::string errorMessage)
{
	std::cout << RED << " * Error : " << RESET << errorMessage << std::endl;
}

void	PmergeMe::print(bool flag)
{
	if (flag == true) {
		std::vector<int>::iterator it_v;
		std::cout << "================== Before : =========================== " << std::endl;
		for (it_v = nbrs1_v.begin(); it_v != nbrs1_v.end(); it_v++) {
			std::cout << *it_v << " ";
		}
		std::cout << std::endl;
		std::cout << "======================================================== " << std::endl;
	}
	else {
		std::vector<int>::iterator it_v;
		std::cout << "================== After : ============================= " << std::endl;
		for (it_v = chain_v.begin(); it_v != chain_v.end(); it_v++) {
			std::cout << *it_v << " ";
		}
		std::cout << std::endl;
		std::cout << "======================================================== " << std::endl;
	}
}

void	PmergeMe::swap(int &x, int &y)
{
	int	tmp;

	tmp = x;
	x = y;
	y = tmp;
}
size_t	PmergeMe::getSize(std::string container)
{
	if (container == "vector")
		return (nbrs1_v.size());
	else if (container == "deque")
		return (nbrs1_d.size());
	return (-1); 
}

// ==================================== Vector Methods ==========================
bool	PmergeMe::find_v(std::vector<int>::iterator begin, std::vector<int>::iterator end, int occurence)
{
	while (begin != end) {
		if (*begin == occurence)
			return false;
		begin++;
	}
	return true;
}

// Step 1 : Parse the input
int	PmergeMe::parseInput_v(std::string av)
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
	nbrs1_v.push_back(std::atoi(av.c_str()));
	return 0;
}

// Step 2 : Check if container's size if not pair ==> pop the struggler
void	PmergeMe::checkVector()
{
	if (nbrs1_v.size() % 2 != 0) {
		struggler = nbrs1_v.back();
		nbrs1_v.pop_back();
		struggler_presence = true;
	}
}

// Step 3 : Divide the container into pairs of numbers and sort it's elements
void	PmergeMe::addPairs_v()
{
	size_t i = 0;
	size_t j = 1;

	while (j < nbrs1_v.size()) {
		nbrs2_v.push_back(std::make_pair(nbrs1_v[i], nbrs1_v[j]));
		i += 2;
		j += 2;
	}
	// Swap pairs
	std::vector<std::pair<int, int> >::iterator it = nbrs2_v.begin();
	while (it != nbrs2_v.end()) {
		if (it->first < it->second)
			swap(it->first, it->second);
		it++;
	}
}

// Step 4 : Sort the pairs based on the first element of each pair
void PmergeMe::sortPairs_v() 
{
	for (size_t i = 0; i < nbrs2_v.size(); ++i) {
		for (size_t j = i + 1; j < nbrs2_v.size(); ++j) {
			if (nbrs2_v[i].first > nbrs2_v[j].first) {
				swap(nbrs2_v[i].first, nbrs2_v[j].first);
				swap(nbrs2_v[i].second, nbrs2_v[j].second);
			}
		}
	}
}

// Step 5 : Stock first elements in main chain and second elements in pend chain
void	PmergeMe::stockInChainAndPend_v()
{
	std::vector<std::pair<int, int> >::iterator	it = nbrs2_v.begin();

	while (it != nbrs2_v.end()) {
		chain_v.push_back(it->first);
		pend_v.push_back(it->second);
		it++;
	}
	// Push first element in Pend to the Main Chain
	std::vector<int>::iterator	it_ = pend_v.begin();
	chain_v.insert(chain_v.begin(), *it_);
}

// Step 6 : The almighty Jaconbs Thal algorithm
void	PmergeMe::jacobsThal_v()
{
	jacobsthal_v.push_back(0);
	jacobsthal_v.push_back(1);
	jacobsthal_v.push_back(1);

	if (jacobsthal_v.size() == 0) {
		error("container is empty.");
		return ;
	}
	size_t i;
	size_t	new_nbr = 0;
	while (new_nbr <= pend_v.size()) {
		i = jacobsthal_v.size();
		new_nbr = (jacobsthal_v[i - 1] * 1) + (jacobsthal_v[i - 2] * 2);
		jacobsthal_v.push_back(new_nbr);
	}
}

// Step 7 : Generating the sequence (It's a pain in the ass :( )
void	PmergeMe::sequenceGen_v()
{
	for (std::vector<int>::iterator it = jacobsthal_v.begin() + 3; it != jacobsthal_v.end(); it++) {
		size_t new_nbr = *it;
		while (find_v(jacobsthal_v.begin(), it, new_nbr)) {
			if (new_nbr > pend_v.size()) {
				new_nbr--;
				continue;
			}
			else
				sequence_v.push_back(new_nbr);
			new_nbr--;
		}
	}
}

// Step 8 : Push elements from pend to chain using merge sort
void	PmergeMe::pushToChain_v()
{
	std::vector<int>::iterator	j = sequence_v.begin();

	while (j != sequence_v.end()) {
		int index = *j - 1;
		if (pend_v[index]) {
			std::vector<int>::iterator it = std::lower_bound(chain_v.begin(), chain_v.end(), pend_v[index]);
			if (it != chain_v.end())
				chain_v.insert(it, pend_v[index]);
		}
		j++;
	}
	if (struggler_presence == true) {
		std::vector<int>::iterator it = std::lower_bound(chain_v.begin(), chain_v.end(), struggler);
			chain_v.insert(it, struggler);
	}
}
// =============================================================================


// ==================================== Deque Methods ==========================
bool	PmergeMe::find_d(std::deque<int>::iterator begin, std::deque<int>::iterator end, int occurence)
{
	while (begin != end) {
		if (*begin == occurence)
			return false;
		begin++;
	}
	return true;
}

// Step 1 : Parse the input
int	PmergeMe::parseInput_d(std::string av)
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
	nbrs1_d.push_back(std::atoi(av.c_str()));
	return 0;
}

// Step 2 : Check if container's size if not pair ==> pop the struggler
void	PmergeMe::checkDeque()
{
	if (nbrs1_d.size() % 2 != 0) {
		struggler = nbrs1_d.back();
		nbrs1_d.pop_back();
		struggler_presence = true;
	}
}

// Step 3 : Divide the container into pairs of numbers and sort it's elements
void	PmergeMe::addPairs_d()
{
	size_t i = 0;
	size_t j = 1;

	while (j < nbrs1_d.size()) {
		nbrs2_d.push_back(std::make_pair(nbrs1_d[i], nbrs1_d[j]));
		i += 2;
		j += 2;
	}
	// Swap pairs
	std::deque<std::pair<int, int> >::iterator it = nbrs2_d.begin();
	while (it != nbrs2_d.end()) {
		if (it->first < it->second)
			swap(it->first, it->second);
		it++;
	}
}

// Step 4 : Sort the pairs based on the first element of each pair
void PmergeMe::sortPairs_d() 
{
	for (size_t i = 0; i < nbrs2_d.size(); ++i) {
		for (size_t j = i + 1; j < nbrs2_d.size(); ++j) {
			if (nbrs2_d[i].first > nbrs2_d[j].first) {
				swap(nbrs2_d[i].first, nbrs2_d[j].first);
				swap(nbrs2_d[i].second, nbrs2_d[j].second);
			}
		}
	}
}

// Step 5 : Stock first elements in main chain and second elements in pend chain
void	PmergeMe::stockInChainAndPend_d()
{
	std::deque<std::pair<int, int> >::iterator	it = nbrs2_d.begin();

	while (it != nbrs2_d.end()) {
		chain_d.push_back(it->first);
		pend_d.push_back(it->second);
		it++;
	}
	// Push first element in Pend to the Main Chain
	std::deque<int>::iterator	it_ = pend_d.begin();
	chain_d.insert(chain_d.begin(), *it_);
}

// Step 6 : The almighty Jaconbs Thal algorithm
void	PmergeMe::jacobsThal_d()
{
	jacobsthal_d.push_back(0);
	jacobsthal_d.push_back(1);
	jacobsthal_d.push_back(1);

	if (jacobsthal_d.size() == 0) {
		error("container is empty.");
		return ;
	}
	size_t i;
	size_t	new_nbr = 0;
	while (new_nbr <= pend_d.size()) {
		i = jacobsthal_d.size();
		new_nbr = (jacobsthal_d[i - 1] * 1) + (jacobsthal_d[i - 2] * 2);
		jacobsthal_d.push_back(new_nbr);
	}
}

// Step 7 : Generating the sequence (It's a pain in the ass :( )
void	PmergeMe::sequenceGen_d()
{
	for (std::deque<int>::iterator it = jacobsthal_d.begin() + 3; it != jacobsthal_d.end(); it++) {
		size_t new_nbr = *it;
		while (find_d(jacobsthal_d.begin(), it, new_nbr)) {
			if (new_nbr > pend_d.size()) {
				new_nbr--;
				continue;
			}
			else
				sequence_d.push_back(new_nbr);
			new_nbr--;
		}
	}
}

// Step 8 : Push elements from pend to chain using merge sort
void	PmergeMe::pushToChain_d()
{
	std::deque<int>::iterator	j = sequence_d.begin();

	while (j != sequence_d.end()) {
		int index = *j - 1;
		if (pend_d[index]) {
			std::deque<int>::iterator it = std::lower_bound(chain_d.begin(), chain_d.end(), pend_d[index]);
			if (it != chain_d.end())
				chain_d.insert(it, pend_d[index]);
		}
		j++;
	}
	if (struggler_presence == true) {
		std::deque<int>::iterator it = std::lower_bound(chain_d.begin(), chain_d.end(), struggler);
			chain_d.insert(it, struggler);
	}
}
// =============================================================================

PmergeMe::~PmergeMe()
{}
