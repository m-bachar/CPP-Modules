#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << " * a is " << a << std::endl;
	std::cout << GREEN << " * b is " << RESET << b << std::endl;
	std::cout << " * c is " << c << std::endl;
	std::cout << GREEN << " * d is " << RESET << d << std::endl;

	std::cout << " * a is " << a.toInt() << " as integer" << std::endl;
	std::cout << GREEN << " * b is " << RESET << b.toInt() << " as integer" << std::endl;
	std::cout << " * c is " << c.toInt() << " as integer" << std::endl;
	std::cout << GREEN << " * d is " << RESET << d.toInt() << " as integer" << std::endl;

	return 0;
}
