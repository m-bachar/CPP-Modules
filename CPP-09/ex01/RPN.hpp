#pragma once

#include <iostream>
#include <sstream>
#include <stack>
#include <cstdlib>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

class RPN
{
	private:
		std::string	input;
		std::stack<int> stack;
	public:
		RPN();
		RPN(std::string input);
		RPN(const RPN &obj);
		RPN	&operator=(const RPN &obj);
		void	error(std::string errorMessage);
		int		parse_input();
		~RPN();
};
