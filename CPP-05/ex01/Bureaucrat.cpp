#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void	Bureaucrat::signForm(Form &obj)
{
	if (obj.getSign() == true)
		std::cout << PURPLE << " * " << getName() << RESET << " signed " << GREEN << obj.getName() << RESET << std::endl;
	else
		std::cout << PURPLE << " * " << getName() << RESET << " couldn't sign " << ORANGE << obj.getName() << RESET << " because" ORANGE << " life is hard lakin jamila." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << " * Bureaucrat " << RESET << "destructor called !" << std::endl;
}
