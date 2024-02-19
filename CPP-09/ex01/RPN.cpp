#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string input)
{
	this->input = input;
}

RPN::RPN(const RPN &obj)
{
	*this = obj;
}

RPN &RPN::operator=(const RPN &obj)
{
    input = obj.input;
    stack = obj.stack;
    return *this;
}

void RPN::error(std::string errorMessage)
{
    std::cout << RED << " * Error : " << RESET << errorMessage << std::endl;
}

int RPN::parse_input()
{
    std::istringstream iss(input);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
            if (std::atoi(token.c_str()) > 9)
                return (error("numbers must be less than 10."), 1);
            stack.push(std::atoi(token.c_str()));
        }
        else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            if (stack.size() < 2)
                return (error("not enough numbers in the stack."), 1);
            int nbr2 = stack.top();
            stack.pop();
            int nbr1 = stack.top();
            stack.pop();

			if (token[0] == '+')
				stack.push(nbr1 + nbr2);
			else if (token[0] == '-')
				stack.push(nbr1 - nbr2);
			else if (token[0] == '*')
				stack.push(nbr1 - nbr2);
			else if (token[0] == '/') {
				if (nbr2 == 0)
                    return (error("division by 0 is impossible."), 1);
                stack.push(nbr1 / nbr2);
			}
        }
        else
            return(error("no operation symbols found."), 1);
    }

    if (stack.size() != 1)
        return (error("not enough members or no operation found."), 1);

    std::cout << GREEN << " * Result = " << RESET << stack.top() << std::endl;
    return 0;
}

RPN::~RPN() {}
