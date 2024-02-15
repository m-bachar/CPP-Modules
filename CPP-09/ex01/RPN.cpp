#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(RPN const &obj)
{
	*this = obj;
}

RPN	&RPN::operator=(RPN const &obj)
{
	input = obj.input;
	return *this;
}

int	RPN::parse_input()
{
	int	i = 0;
	while (input[i])
	{
		
	}
}

RPN::~RPN()
{}
