#pragma once

#include <iostream>
#include <stack>
#include <iterator>
#include <algorithm>
#include <deque>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

class RPN
{
	private:
		std::string	input;
		std::deque<int> nbrs;
		std::deque<std::string> ops;
	public:
		RPN();
		RPN(std::string input);
		RPN(const RPN &obj);
		RPN	&operator=(const RPN &obj);
		int		parse_input();
		void	error(std::string errorMessage);
		int		fillAndParse();
		int		mergeDeques();
		~RPN();
};