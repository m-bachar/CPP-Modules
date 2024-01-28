#include "MutantStack.hpp"

int main()
{
	MutantStack<int> ms;

	ms.push(5);
	ms.push(17);
	ms.push(3);
	ms.push(5);
	ms.push(737);
	ms.push(0);

	std::cout << ORANGE << " * ms top : " << RESET << ms.top() << std::endl;
	ms.pop();
	std::cout << ORANGE << " * ms top : " << RESET << ms.top() << std::endl;

	MutantStack<int>::iterator it;

	std::cout << GREEN << " * ms content : " << RESET;
	for (it = ms.begin(); it != ms.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return 0;
}
