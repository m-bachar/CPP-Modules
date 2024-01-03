#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Richard"), sign(false), sign_grade(5), execute_grade(5)
{
	std::cout << GREEN << " * Form " << RESET << "default constructor called !" << std::endl;
}

Form::Form(std::string namee, int sign_gradee) : name(namee), sign(false), sign_grade(sign_gradee), execute_grade(5)
{
	std::cout << GREEN << " * Form " << RESET << "parametrized constructor called !" << std::endl;
}

Form::Form(const Form &obj) : name("Richard"), sign(false), sign_grade(5), execute_grade(5)
{
	(void)obj;
}

Form	&Form::operator=(const Form &obj)
{
	(void)obj;
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
	return sign_grade;
}

int	Form::getExecuteGrade()
{
	return execute_grade;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return " grade is too high ! ";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return " grade is too low ! ";
}

std::ostream	&operator<<(std::ostream &os, Form &obj)
{
	os << PURPLE << " * Name          : " << RESET << obj.getName() << std::endl;
	os << PURPLE << " * Signed        : " << RESET << obj.getSign() << std::endl;
	os << PURPLE << " * Sign Grade    : " << RESET << obj.getSignGrade() << std::endl;
	os << PURPLE << " * Execute Grade : " << RESET << obj.getExecuteGrade() << std::endl;
	return os;
}

void	Form::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() <= getSignGrade())
	{
		std::cout << " * Grade = " << getSignGrade() << std::endl;
		sign = true;
	}
	else
		throw GradeTooLowException();
}

Form::~Form()
{
	std::cout << RED << " * Form " << RESET << "destructor called !" << std::endl;
}
