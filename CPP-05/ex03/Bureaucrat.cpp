#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Benito"), grade(5)
{
	std::cout << GREEN << " * Bureaucrat " << RESET << "default constructor called !" << std::endl;
}

Bureaucrat::Bureaucrat(std::string namee, int gradee) : name(namee)
{
	std::cout << GREEN << " * Bureaucrat " << RESET << "parametrized constructor called !" << std::endl;
	grade = gradee;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	*this = obj;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	(std::string)name = obj.name;
	grade = obj.grade;
	return *this;
}

std::string	Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::incrementGrade()
{
	grade--;
	if (grade < 1)
		throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade()
{
	grade++;
	if (grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(AForm &obj)
{
	if (getGrade() <= obj.getSignGrade())
		std::cout << PURPLE << " * " << getName() << RESET << " signed " << GREEN << obj.getName() << RESET << std::endl;
	else
		std::cout << PURPLE << " * " << getName() << RESET << " couldn't sign " << RED << obj.getName() << RESET << " because " << ORANGE << "Mogheeww" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << " * Bureaucrat " << RESET << "destructor called !" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade too low.";
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try {
		form.execute(*this);
		std::cout << GREEN << " * " << getName() << RESET << " executed " << GREEN << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << " * " << getName() << RESET << " could not execute " << RED << form.getName() << RESET << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat &obj)
{
	std::cout << PURPLE << " * " << obj.getName() << RESET << ", bureaucrate grade " << PURPLE << obj.getGrade() << RESET << std::endl;
	return os;
}
