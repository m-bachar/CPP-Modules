#include "Base.hpp"
#include "utils.hpp"

int main()
{
	std::cout << ORANGE << " * Tests using identify(Base* p) function !" << RESET << std::endl;
	Base *x = generate();
	identify(x);
	delete x;

	std::cout << ORANGE << " * Tests using identify(Base& p) function !" << RESET << std::endl;
	Base *y = generate();
	Base &z = *y;
	identify(z);
	delete &z;

	Base a;
	return 0;
}
