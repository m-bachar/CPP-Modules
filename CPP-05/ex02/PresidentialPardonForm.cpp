#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Formax", false, 145, 137)
{
	std::cout << GREEN << " * PresidentialPardonForm " << RESET << "default constructor called !" << std::endl;
	target = "Formax";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Formax", false, 145, 137)
{
	std::cout << GREEN << " * PresidentialPardonForm " << RESET << "parametrized constructor called !" << std::endl;
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
{
	*this = obj;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	this->target = obj.target;
	return *this;
}

int	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getSignGrade() && !getSign())
	{
		std::cout << RED << " * " << target << RESET << " hasn't been pardoned !" << std::endl;
		throw GradeTooLowException();
		return 1;
	}
	std::cout << GREEN << " * " << target << RESET << " has been pardoned by " << GREEN << "Zaphod Beeblebrox" << RESET << std::endl;
	return 0;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << " * PresidentialPardonForm " << RESET << "destructor called !" << std::endl;
}
