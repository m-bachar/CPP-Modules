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

		std::cout << "================== Before : ============================= " << std::endl;
		std::vector<int>::iterator it;
		for (it = pmm.nbrs1.begin(); it != pmm.nbrs1.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "======================================================== " << std::endl;
		clock_t	v_start = clock();
		pmm.checkVector();
		pmm.addPairs();
		pmm.sortPairs();
		pmm.stockInChainAndPend();
		pmm.jacobsThal();
		pmm.sequenceGen();
		pmm.pushToChain();
		clock_t	v_end = clock();
		double v_time_taken = double(v_end - v_start) / CLOCKS_PER_SEC * 1000.0; 
		std::cout << "================== After : ============================= " << std::endl;
		for (it = pmm.chain.begin(); it != pmm.chain.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "======================================================== " << std::endl;
		std::cout << PURPLE << " * Time taken by vector to process a range of " << GREEN << pmm.nbrs1.size() << PURPLE << " numbers is : " << ORANGE << v_time_taken << " us." << RESET << std::endl;
	}
	else {
		std::cout << RED << " * Error : " << RESET << "invalid arguments count." << std::endl;
		return 1;
	}
	return 0;
}
