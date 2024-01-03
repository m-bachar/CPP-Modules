#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Benito")
{
	std::cout << GREEN << " * Bureaucrat " << RESET << "default constructor called ! " << std::endl;
	grade = 1;
}

Bureaucrat::Bureaucrat(int grade) : name("Benito")
{	
	std::cout << GREEN << " * Bureaucrat " << RESET << "parametrized constructor called ! " << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	*this = obj;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	this->grade = obj.grade;
	return *this;
}

std::string	Bureaucrat::getName()
{
	return name;
}

int	Bureaucrat::getGrade()
{
	return grade;
}

void	Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return " grade is too high ! ";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return " grade is too low ! ";
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat &obj)
{
	os << PURPLE << " * " << obj.getName() << RESET << ", bureaucrate grade " << ORANGE << obj.getGrade() << RESET << "." << std::endl;
	return os;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << " * Bureaucrat " << RESET << "destructor called !" << std::endl;
}
