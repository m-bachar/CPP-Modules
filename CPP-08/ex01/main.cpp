#include "Span.hpp"

int main()
{
	try {
		Span sp = Span(N);

		sp.burn_the_cpu_or_u_gay();

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << GREEN << " * Sorted List : " << RESET;

		sp.lst.sort();
		std::list<int>::iterator it_;
		for (it_ = sp.lst.begin(); it_ != sp.lst.end(); it_++)
			std::cout << *it_ << " ";
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << " * Error " << RESET << e.what() << std::endl;
	}
}
