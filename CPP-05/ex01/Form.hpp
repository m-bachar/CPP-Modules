#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:
		const std::string	name;
		bool				sign;
		const int			sign_grade;
		const int			execute_grade;
	public:
		Form();
		Form(std::string namee, int sign_gradee);
		Form(const Form &obj);
		Form	&operator=(const Form &obj);
		std::string	getName();
		bool		getSign();
		int			getSignGrade();
		int			getExecuteGrade();
		class GradeTooHighException: public std::exception
		{
			const char	*what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			const char	*what() const throw();
		};
		void	beSigned(Bureaucrat &obj);
		~Form();
};

std::ostream	&operator<<(std::ostream &os, Form &obj);
