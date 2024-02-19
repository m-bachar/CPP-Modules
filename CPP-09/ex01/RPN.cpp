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
    nbrs = obj.nbrs;
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
    std::stack<int> stack;

    while (iss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) // Check if token is a number
            stack.push(std::stoi(token));
        else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            if (stack.size() < 2) {
                error("not enough numbers in the stack.");
                return 1;
            }
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

			if (token[0] == '+')
				stack.push(operand1 + operand2);
			else if (token[0] == '-')
				stack.push(operand1 - operand2);
			else if (token[0] == '*')
				stack.push(operand1 - operand2);
			else if (token[0] == '/') {
				if (operand2 == 0) {
                    error("division by 0 is impossible.");
                    return 1;
                }
                stack.push(operand1 / operand2);
			}
        }
        else {
            error("no operation symbols found.");
            return 1;
        }
    }

    if (stack.size() != 1) {
        error("Invalid expression format.");
        return 1;
    }

    std::cout << GREEN << " * Result = " << RESET << stack.top() << std::endl;
    return 0;
}

RPN::~RPN() {}
