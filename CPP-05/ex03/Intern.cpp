#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << GREEN << " * Intern " << RESET << "default constructor called !" << std::endl;
}

Intern::Intern(const Intern &obj)
{
	*this = obj;
}

Intern	&Intern::operator=(const Intern &obj)
{
	this->formName = obj.formName;
	this->target = obj.target;
	return *this;
}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	AForm	*ptr;

	std::string	forms[4];
	int i = 0;
	forms[0] = "shrubbery request";
	forms[1] = "robotomy request";
	forms[2] = "presidential pardon request";

	while (i < 4)
	{
		if (formName == forms[i])
		{
			switch (i)
			{
				case 0:
					std::cout << " * Intern creates " << GREEN << formName << RESET << std::endl;
					ptr = new ShrubberyCreationForm(target);
					return ptr;
				case 1:
					std::cout << " * Intern creates " << GREEN << formName << RESET << std::endl;
					ptr = new RobotomyRequestForm(target);
					return ptr;
				case 2:
					std::cout << " * Intern creates " << GREEN << formName << RESET << std::endl;
					ptr = new PresidentialPardonForm(target);
					return ptr;
				default:
					break;
			}
		}
		i++;
	}
	std::cout << RED << " * Error " << RESET << "form name not found !" << std::endl;
	return NULL;
}

Intern::~Intern()
{
	std::cout << RED << " * Intern " << RESET << "destructor called !" << std::endl;
}
