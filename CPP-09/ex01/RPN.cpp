#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(std::string input)
{
	this->input = input;
}

RPN::RPN(RPN const &obj)
{
	*this = obj;
}

RPN	&RPN::operator=(RPN const &obj)
{
	input = obj.input;
	nbrs = obj.nbrs;
	ops = obj.ops;
	return *this;
}

void	RPN::error()
{
	std::cout << RED << " * Error" << RESET << std::endl;
}

int	RPN::parse_input()
{
	int	i = 0;
	while (input[i])
	{
		if (!std::isdigit(input[i]) && input[i] != '-' && input[i] != '+' && input[i] != '*' && input[i] != '/' && input[i] != ' ') {
			error();
			return 1;
		}
		i++;
	}
	if (fillAndParse())
		return 1;
	return 0;
}

int	RPN::fillAndParse()
{
	size_t	beg_pos = 0;
	size_t	end_pos = input.find(' ');
	if (end_pos == std::string::npos) {
		error();
		return 1;
	}
	while (true)
	{
		std::string	chunk = input.substr(beg_pos, 1);
		beg_pos = end_pos + 1;
		end_pos = input.find(' ', beg_pos);
		if (chunk == "-" || chunk == "+" || chunk == "*" || chunk == "/")
			ops.push_back(chunk);
		else {
			if (std::atoi(chunk.c_str()) > 10) {
				error();
				return 1;
			}
			nbrs.push_back(std::atoi(chunk.c_str()));
		}
		if (end_pos == std::string::npos)
			break ;
	}
	// Refactor and change this code
	std::string last_chunk = input.substr(beg_pos);
    if (!last_chunk.empty()) {
        if (last_chunk == "-" || last_chunk == "+" || last_chunk == "*" || last_chunk == "/")
            ops.push_back(last_chunk);
        else {
            if (std::atoi(last_chunk.c_str()) > 10) {
                error();
                return 1;
            }
            nbrs.push_back(std::atoi(last_chunk.c_str()));
        }
    }
	if (mergeDeques())
		return 1;
	return 0;
}

// Check ./RPN "1 2 * 2 / 2 * 2 4 - +" case
int	RPN::mergeDeques()
{
	std::string	op;
	int			nbr_1 = 0;
	int			nbr_2 = 0;
	int			result = 0;

	while (!nbrs.empty() && !ops.empty())
	{
		nbr_1 = nbrs.front();
		nbrs.pop_front();
		nbr_2 = nbrs.front();
		nbrs.pop_front();
		op = ops.front();
		ops.pop_front();
		if (op == "+")
			result = nbr_1 + nbr_2;
		else if (op == "-")
			result = nbr_1 - nbr_2;
		else if (op == "*")
			result = nbr_1 * nbr_2;
		else if (op == "/") {
			if (nbr_2 == 0) {
				error();
				return 1;
			}
			result = nbr_1 / nbr_2;
		}
		nbrs.push_front(result);
	}
	std::cout << GREEN << " * Result = " << RESET << nbrs.front() << std::endl;
	return 0;
}

RPN::~RPN()
{}
