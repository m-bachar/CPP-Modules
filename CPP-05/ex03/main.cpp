#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	{
        try {
            Intern someRandomIntern;
            AForm* scf;
            scf = someRandomIntern.makeForm("shrubbery request", "Bender");
        }
        catch (std::exception &e) {
            std::cout << RED << " * Error : " << RESET << e.what() << std::endl;
        }
    }
	{
        try {
            Intern someRandomIntern;
            AForm* rrf;
            rrf = someRandomIntern.makeForm("robotomy request", "Denber");
        }
        catch (std::exception &e) {
            std::cout << RED << " * Error : " << RESET << e.what() << std::endl;
        }
    }
	{
        try {
            Intern someRandomIntern;
            AForm* ppf;
            ppf = someRandomIntern.makeForm("presidential pardon request", "Renbed");
        }
        catch (std::exception &e) {
            std::cout << RED << " * Error : " << RESET << e.what() << std::endl;
        }
    }
	{
        try {
            Intern someRandomIntern;
            AForm* ppf;
            ppf = someRandomIntern.makeForm("mogheeww", "Rendeb");
        }
        catch (std::exception &e) {
            std::cout << RED << " * Error : " << RESET << e.what() << std::endl;
        }
    }
}
