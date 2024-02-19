#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
	if (ac > 2) {
		PmergeMe	pmm;
		int i = 1;
		while (av[i]) {
			if (pmm.parseInput_v(av[i]))
				return 1;
			i++;
		}
		i = 1;
		while (av[i]) {
			if (pmm.parseInput_d(av[i]))
				return 1;
			i++;
		}

		pmm.print(true);
		// Vector Chunk
		clock_t	v_start = clock();
		pmm.checkVector();
		pmm.addPairs_v();
		pmm.sortPairs_v();
		pmm.stockInChainAndPend_v();
		pmm.jacobsThal_v();
		pmm.sequenceGen_v();
		pmm.pushToChain_v();
		clock_t	v_end = clock();
		double v_time_taken = double(v_end - v_start) / CLOCKS_PER_SEC * 1000.0; 
	
		// Deque Chunk
		clock_t	d_start = clock();
		pmm.checkDeque();
		pmm.addPairs_d();
		pmm.sortPairs_d();
		pmm.stockInChainAndPend_d();
		pmm.jacobsThal_d();
		pmm.sequenceGen_d();
		pmm.pushToChain_d();
		pmm.print(false);
		clock_t	d_end = clock();
		double d_time_taken = double(d_end - d_start) / CLOCKS_PER_SEC * 1000.0; 

		std::cout << PURPLE << " * Time taken by Vector to process a range of " << GREEN << pmm.getSize("vector") << PURPLE << " numbers is : " << ORANGE << v_time_taken << " us." << RESET << std::endl;
		std::cout << PURPLE << " * Time taken by Deque to process a range of  " << GREEN << pmm.getSize("deque") << PURPLE << " numbers is : " << ORANGE << d_time_taken << " us." << RESET << std::endl;
	}
	else {
		std::cout << RED << " * Error : " << RESET << "invalid arguments count." << std::endl;
		return 1;
	}
	return 0;
}
