#pragma once

#include "Bureaucrat.hpp"

class Intern
{
	private:
		std::string formName;
		std::string	target;
	public:
		Intern();
		Intern(const Intern &obj);
		Intern	&operator=(const Intern &obj);
		AForm	*makeForm(std::string formName, std::string target);
		~Intern();
};
