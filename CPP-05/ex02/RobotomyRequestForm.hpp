#pragma once

#include "Bureaucrat.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &obj);
		int	execute(Bureaucrat const & executor) const;
		~RobotomyRequestForm();
};