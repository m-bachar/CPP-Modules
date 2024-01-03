#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a(150);
	try {
		a.decrementGrade();
	}
	catch (std::exception &e) {
		std::cout << RED << " * Error :" << RESET << e.what() << std::endl;
	}
	Bureaucrat b(1);
	try {
		b.incrementGrade();
	}
	catch (std::exception &e) {
		std::cout << RED << " * Error :" << RESET << e.what() << std::endl;
	}

	Bureaucrat c(150);

	std::cout << c;
}
