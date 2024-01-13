#include "AForm.hpp"

AForm::AForm() : name("Benito"), sign(false), signGrade(145), executeGrade(137)
{
	std::cout << GREEN << " * AForm " << RESET << "default constructor called !" << std::endl;
	if (signGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 1)
		throw GradeTooHighException();
}

AForm::AForm(std::string namee, bool signn, int signGradee, int executeGradee) : name(namee), sign(signn), signGrade(signGradee), executeGrade(executeGradee)
{
	std::cout << GREEN << " * AForm " << RESET << "parametrized constructor called !" << std::endl;
	if (signGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &obj) : signGrade(obj.signGrade), executeGrade(obj.executeGrade)
{
	*this = obj;
}

AForm	&AForm::operator=(const AForm &obj)
{
	(std::string)this->name = obj.name;
	this->sign = obj.sign;
	return *this;
}

std::string	AForm::getName() const
{
	return name;
}

bool AForm::getSign() const
{
	return sign;
}

int	AForm::getSignGrade() const
{
	return signGrade;
}

int AForm::getExecuteGrade() const
{
	return executeGrade;
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

void	AForm::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() < getSignGrade())
		sign = true;
	else
		throw GradeTooLowException();
}

AForm::~AForm()
{
	std::cout << RED << " * AForm " << RESET << "destructor called !" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, AForm &obj)
{
	std::cout << PURPLE << " * Name\t\t : " << RESET << obj.getName() << std::endl;
	if (obj.getSign() == true)
		std::cout << PURPLE << " * Sign\t\t : " << RESET << "signed" << std::endl;
	else
		std::cout << PURPLE << " * Sign\t\t : " << RESET << "not signed" << std::endl;
	std::cout << PURPLE << " * Sign Grade\t : " << RESET << obj.getSignGrade() << std::endl;
	std::cout << PURPLE << " * Execute Grade : " << RESET << obj.getExecuteGrade() << std::endl;
	return os;
}
