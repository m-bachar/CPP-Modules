#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Formax", false, 145, 137)
{
	std::cout << GREEN << " * RobotomyRequestForm " << RESET << "default constructor called !" << std::endl;
	target = "Benito";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Formax", false, 145, 137)
{
	std::cout << GREEN << " * RobotomyRequestForm " << RESET << "parametrized constructor called !" << std::endl;
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
{
	*this = obj;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	target = obj.target;
	return *this;
}

int	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getSignGrade() && !getSign())
		throw GradeTooLowException();
	srand(time(NULL));
	int randomNumber = rand() % 2;
	if (randomNumber == 1)
	{
		std::cout << GREEN << " * " << target << RESET << " has been robotomized " << GREEN << "successfully" << RESET << std::endl;
		return 0;
	}
	else
	{
		std::cout << RED << " * " << target << "'s" << RESET << " robotomy has " << RED << "failed" << RESET << std::endl;
		return 1;
	}
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << " * RobotomyRequestForm " << RESET << "destructor called !" << std::endl;
}
