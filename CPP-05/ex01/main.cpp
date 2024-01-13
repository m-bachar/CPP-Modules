#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat a("Benito", 6);
		Form b("Formax", true, 5, 0);
		std::cout << a;
		a.signForm(b);
	}
	catch (std::exception &e) {
		std::cout << RED << " * Error : " << RESET << e.what() << std::endl;
	}
}
