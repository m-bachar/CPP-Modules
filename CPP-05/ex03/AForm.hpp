#pragma once

#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;
class AForm {
	private:
		const std::string	name;
		bool				sign;
		const int			signGrade;
		const int			executeGrade;
	public:
		AForm();
		AForm(std::string namee, bool signn, int signGradee, int executeGradee);
		AForm(const AForm &obj);
		AForm	&operator=(const AForm &obj);
		std::string	getName() const;
		bool		getSign() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;
		void		beSigned(Bureaucrat &obj);
		virtual int	execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException : public std::exception {
			public:
				const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char	*what() const throw();
		};
		virtual ~AForm();
};

std::ostream	&operator<<(std::ostream &os, AForm &obj);
