#include "Array.hpp"

int main()
{
	try {
		Array<int> a(5);
		a[0] = 'A';
		a[1] = 'B';
		a[2] = 'C';
		a[3] = 'D';
		a[4] = 'E';
		std::cout << " * " << a[0] << std::endl;
		std::cout << " * " << a[1] << std::endl;
		std::cout << " * " << a[2] << std::endl;
		std::cout << " * " << a[3] << std::endl;
		std::cout << " * " << a[4] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << " * Error : " << RESET << e.what() << std::endl;
	}
}
