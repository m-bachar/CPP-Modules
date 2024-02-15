#pragma once

#include <iostream>
#include <stack>
#include <iterator>
#include <algorithm>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

class RPN
{
	private:
		std::string	input;
	public:
		RPN();
		RPN(const RPN &obj);
		RPN	&operator=(const RPN &obj);
		int	parse_input();
		~RPN();
};
