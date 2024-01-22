#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	Base *ptr;

	srand(time(NULL));
	int randomNumber = (rand() % 3) + 1;
	if (randomNumber == 1)
		return ptr = new A();
	else if (randomNumber == 2)
		return ptr = new B();
	else
		return ptr = new C();
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << PURPLE << " * Class A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << PURPLE << " * Class B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << PURPLE << " * Class C" << RESET << std::endl;
}

void	identify(Base& p)
{
	try
	{
		if (!dynamic_cast<A*>(&p))
			throw "error";
		std::cout << PURPLE << " * Class A" << RESET << std::endl;
	}
	catch (const char *)
	{
		std::cout << RED << " * Error : " << RESET << "Dynamic cast of (A) threw an error !" << std::endl;
	}
	try
	{
		if (!dynamic_cast<B*>(&p))
			throw "error";
		std::cout << PURPLE << " * Class B" << RESET << std::endl;
	}
	catch (const char *)
	{
		std::cout << RED << " * Error : " << RESET << "Dynamic cast of (B) threw an error !" << std::endl;
	}
	try
	{
		if (!dynamic_cast<C*>(&p))
			throw "error";
		std::cout << PURPLE << " * Class C" << RESET << std::endl;
	}
	catch (const char *)
	{
		std::cout << RED << " * Error : " << RESET << "Dynamic cast of (C) threw an error !" << std::endl;
	}
}
