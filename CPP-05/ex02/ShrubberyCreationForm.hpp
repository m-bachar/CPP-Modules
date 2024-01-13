#pragma once

#include "Bureaucrat.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &obj);
		int	execute(Bureaucrat const & executor) const;
		~ShrubberyCreationForm();
};
