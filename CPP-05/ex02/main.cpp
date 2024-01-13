#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat    br("Benitox", 145);

    AForm    *scf =  new ShrubberyCreationForm("Pkhew");
    br.executeForm(*scf);
    AForm    *rrf =  new RobotomyRequestForm("Pkhew");
    br.executeForm(*rrf);
    AForm    *ppf =  new PresidentialPardonForm("Pkhew");
    br.executeForm(*ppf);

    delete scf;
    delete rrf;
    delete ppf;
}
