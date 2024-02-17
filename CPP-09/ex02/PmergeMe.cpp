#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	*this = obj;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &obj)
{
	nbrs1 = obj.nbrs1;
	return *this;
}

void	PmergeMe::error(std::string errorMessage)
{
	std::cout << RED << " * Error : " << RESET << errorMessage << std::endl;
}

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

void	PmergeMe::checkVector()
{
	if (nbrs1.size() % 2 != 0) {
		struggler = nbrs1.back();
		nbrs1.pop_back();
	}
	else {
		
	}
}

PmergeMe::~PmergeMe()
{}
