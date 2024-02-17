#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
	if (ac > 2) {
		PmergeMe	pmm;
		int i = 1;
		while (av[i]) {
			if (pmm.parseInput(av[i]))
				return 1;
			i++;
		}
		std::vector<int>::iterator	it = pmm.nbrs1.begin();
		int j = 0;
		std::cout << ORANGE << "=========================================" << RESET << std::endl;
		while (it != pmm.nbrs1.end()) {
			std::cout << GREEN << " * Number " << j << " = " << RESET << *it << std::endl;
			j++;
			it++;
		}
		pmm.checkVector();
		j = 0;
		it = pmm.nbrs1.begin();
		std::cout << ORANGE << "=========================================" << RESET << std::endl;
		while (it != pmm.nbrs1.end()) {
			std::cout << GREEN << " * Number " << j << " = " << RESET << *it << std::endl;
			j++;
			it++;
		}
		std::cout << ORANGE << "=========================================" << RESET << std::endl;
	}
	else {
		std::cout << RED << " * Error : " << RESET << "invalid arguments count." << std::endl;
		return 1;
	}
	return 0;
}
