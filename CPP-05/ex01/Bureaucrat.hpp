#pragma once

#include <iostream>
#include <exception>
#include "Form.hpp"

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat	&operator=(const Bureaucrat &obj);
		std::string	getName();
		int			getGrade();
		void		incrementGrade();
		void		decrementGrade();
		class GradeTooHighException: public std::exception
		{
			const char	*what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char	*what() const throw();
		};
		void	signForm(Form &obj);
		~Bureaucrat();
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat &obj);
