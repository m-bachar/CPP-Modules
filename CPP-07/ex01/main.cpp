#include "iter.hpp"

void	moghew(char &x)
{
	if (x >= 'a' && x <= 'z')
		x = static_cast<char>(std::toupper(x));
}

int main()
{
	std::string x = "hello world";
	std::cout << PURPLE << " * Before ::iter : " << RESET << x << std::endl;
	::iter(x, x.length(), moghew);
	std::cout << PURPLE << " * After  ::iter : " << RESET << x << std::endl;
}
