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
	return *this;
}

void	RPN::error(std::string errorMessage)
{
	std::cout << RED << " * Error : " << RESET << errorMessage << std::endl;
}

int	RPN::parse_input()
{
	int	i = 0;

	if (input.empty()) {
		error("empty input.");
		return 1;
	}
	while (input[i])
	{
		if (!std::isdigit(input[i]) && input[i] != '-' && input[i] != '+' && input[i] != '*' && input[i] != '/' && input[i] != ' ') {
			error("a different character found other than digits and (- + * /).");
			return 1;
		}
		if ((input[i] == '-' || input[i] == '+' || input[i] == '*' || input[i] == '/') && input[i + 1] && input[i + 1] != ' ') {
			error("digits and operations must be separated with a space.");
			return 1;
		}
		i++;
	}
	i = 0;
	while (input[i])
	{
		if (input[i] == ' ' && input[i + 1] && input[i + 1] == ' ') {
			error("digits and operations must be separated with ONE space ONLY.");
			return 1;
		}
		i++;
	}
	if (input[input.length() - 1] == ' ') {
		error("the input should not end with a whitespace.");
		return 1;
	}
	if (fillAndParse())
		return 1;
	std::deque<int>::iterator it = nbrs.begin();
	std::cout << GREEN << " * Result =  " << RESET << *it << std::endl;
	return 0;
}

int	RPN::fillAndParse()
{
	int	i = 0;
	while (input[i]) {
		if (i % 2 == 0 && !std::isdigit(input[i]) && input[i] != '-' && input[i] != '+' && input[i] != '/' && input[i] != '*') {
			error("a different character other than digits and (- + / *) is present in the input.");
			return 1;
		}
		if (std::isdigit(input[i])) {
			std::string nbr = input.substr(i, 1);
			if (std::atoi(nbr.c_str()) < 0 || std::atoi(nbr.c_str()) > 9) {
				error("number should be between (0 - 9).");
				return 1;
			}
			nbrs.push_back(std::atoi(nbr.c_str()));
		}
		if (input[i] == '+' && !nbrs.empty() && nbrs.size() >= 2) {
			if (nbrs.size() > 2) {
				int tmp = nbrs.front();
				nbrs.pop_front();
				int	nbr1 = nbrs.front();
				nbrs.pop_front();
				int	nbr2 = nbrs.front();
				nbrs.pop_front();
				nbrs.push_front(nbr1 + nbr2);
				nbrs.push_front(tmp);
			}
			else {
				int nbr1 = nbrs.front();
				nbrs.pop_front();
				int nbr2 = nbrs.front();
				nbrs.pop_front();
				nbrs.push_front(nbr1 + nbr2);
			}
		}
		if (input[i] == '-' && !nbrs.empty() && nbrs.size() >= 2) {
			if (nbrs.size() > 2) {
				int tmp = nbrs.front();
				nbrs.pop_front();
				int	nbr1 = nbrs.front();
				nbrs.pop_front();
				int	nbr2 = nbrs.front();
				nbrs.pop_front();
				nbrs.push_front(nbr1 - nbr2);
				nbrs.push_front(tmp);
			}
			else {
				int nbr1 = nbrs.front();
				nbrs.pop_front();
				int nbr2 = nbrs.front();
				nbrs.pop_front();
				nbrs.push_front(nbr1 - nbr2);
			}
		}
		if (input[i] == '/' && !nbrs.empty() && nbrs.size() >= 2) {
			if (nbrs.size() > 2) {
				int tmp = nbrs.front();
				nbrs.pop_front();
				int	nbr1 = nbrs.front();
				nbrs.pop_front();
				int	nbr2 = nbrs.front();
				nbrs.pop_front();
				if (nbr2 == 0) {
					error("a number can not be divided by 0.");
					return 1;
				}
				nbrs.push_front(nbr1 / nbr2);
				nbrs.push_front(tmp);
			}
			else {
				int nbr1 = nbrs.front();
				nbrs.pop_front();
				int nbr2 = nbrs.front();
				nbrs.pop_front();
				if (nbr2 == 0) {
					error("a number can not be divided by 0.");
					return 1;
				}
				nbrs.push_front(nbr1 / nbr2);
			}
		}
		if (input[i] == '*' && !nbrs.empty() && nbrs.size() >= 2) {
			if (nbrs.size() > 2) {
				int tmp = nbrs.front();
				nbrs.pop_front();
				int	nbr1 = nbrs.front();
				nbrs.pop_front();
				int	nbr2 = nbrs.front();
				nbrs.pop_front();
				nbrs.push_front(nbr1 * nbr2);
				nbrs.push_front(tmp);
			}
			else {
				int nbr1 = nbrs.front();
				nbrs.pop_front();
				int nbr2 = nbrs.front();
				nbrs.pop_front();
				nbrs.push_front(nbr1 * nbr2);
			}
		}
		i++;
	}
	return 0;
}

RPN::~RPN()
{}
