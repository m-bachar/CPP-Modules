#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat a(6);
	Form c("Registration", 0);
	try
	{
		c.beSigned(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << " * Error :" << RESET << e.what() << '\n';
	}
	a.signForm(c);
	std::cout << c;
}
