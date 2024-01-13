#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
	private:
		const std::string	name;
		bool				sign;
		const int			signGrade;
		const int			executeGrade;
	public:
		Form();
		Form(std::string namee, bool signn, int signGradee, int executeGradee);
		Form(const Form &obj);
		Form	&operator=(const Form &obj);
		std::string	getName();
		bool		getSign();
		int			getSignGrade();
		int			getExecuteGrade();
		void		beSigned(Bureaucrat &obj);
		class GradeTooHighException : public std::exception {
			public:
				const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char	*what() const throw();
		};
		~Form();
};

std::ostream	&operator<<(std::ostream &os, Form &obj);
