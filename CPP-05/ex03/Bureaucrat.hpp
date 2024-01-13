#pragma once

#include <iostream>
#include "AForm.hpp"

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

class AForm;
class Bureaucrat {
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string namee, int gradee);
		Bureaucrat(const Bureaucrat &obj);
		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(AForm &obj);
		void		executeForm(AForm const & form);
		class GradeTooHighException : public std::exception {
			public:
                const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
                const char* what() const throw();
		};
		Bureaucrat	&operator=(const Bureaucrat &obj);
		~Bureaucrat();
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat &obj);