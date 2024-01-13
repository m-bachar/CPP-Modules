#include "Bureaucrat.hpp"

int main()
{
	/*	First Attempt	*/
	try {
		Bureaucrat a("Benitoo", 0);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << " * Error : " << RESET << e.what() << std::endl;
	}
	/*	Second Attempt	*/
	try {
		Bureaucrat a("Benito", 1);
		std::cout << a << std::endl;
		a.incrementGrade();
	}
	catch (std::exception &e) {
		std::cout << RED << " * Error : " << RESET << e.what() << std::endl;
	}
	/*	Third Attempt	*/
	try {
		Bureaucrat a("PewPew", 151);
		std::cout << a << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << " * Error : " << RESET << e.what() << std::endl;
	}
	/*	Fourth Attempt	*/
	try {
		Bureaucrat a("Pkheew", 150);
		std::cout << a << std::endl;
		a.decrementGrade();
	}
	catch (std::exception &e) {
		std::cout << RED << " * Error : " << RESET << e.what() << std::endl;
	}
}
