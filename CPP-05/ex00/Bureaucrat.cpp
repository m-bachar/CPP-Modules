#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << GREEN << " * Bureaucrat " << RESET << "default constructor called ! " << std::endl;
	grade = 1;
}

Bureaucrat::Bureaucrat(int grade)
{	
	std::cout << GREEN << " * Bureaucrat " << RESET << "parametrized constructor called ! " << std::endl;
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
	if (grade > 0)
		grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (grade < 150)
		grade++;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << " * Bureaucrat " << RESET << "destructor called !" << std::endl;
}
