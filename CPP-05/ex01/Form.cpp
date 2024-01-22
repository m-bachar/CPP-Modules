#include "Form.hpp"

Form::Form() : name("Benito"), sign(false), signGrade(5), executeGrade(5)
{
	std::cout << GREEN << " * Form " << RESET << "default constructor called !" << std::endl;
	if (signGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 1)
		throw GradeTooHighException();
}

Form::Form(std::string namee, bool signn, int signGradee, int executeGradee) : name(namee), sign(signn), signGrade(signGradee), executeGrade(executeGradee)
{
	std::cout << GREEN << " * Form " << RESET << "parametrized constructor called !" << std::endl;
	if (signGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &obj) : signGrade(obj.signGrade), executeGrade(obj.executeGrade)
{
	*this = obj;
}

Form	&Form::operator=(const Form &obj)
{
	Form(obj.name, obj.sign, obj.signGrade, obj.executeGrade);
	return *this;
}

std::string	Form::getName()
{
	return name;
}

bool	Form::getSign()
{
	return sign;
}

int	Form::getSignGrade()
{
	return signGrade;
}

int Form::getExecuteGrade()
{
	return executeGrade;
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

void	Form::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() < getSignGrade())
		sign = true;
	else
		throw GradeTooLowException();
}

Form::~Form()
{
	std::cout << RED << " * Form " << RESET << "destructor called !" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, Form &obj)
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
