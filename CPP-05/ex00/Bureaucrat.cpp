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
	Bureaucrat(obj.name, obj.grade);
	return *this;
}

std::string	Bureaucrat::getName()
{
	return (name);
}

int	Bureaucrat::getGrade()
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

std::ostream	&operator<<(std::ostream &os, Bureaucrat &obj)
{
	std::cout << PURPLE << " * " << obj.getName() << RESET << ", bureaucrate grade " << PURPLE << obj.getGrade() << RESET << std::endl;
	return os;
}
