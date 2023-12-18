#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

/*-----				Default Constructor				-----*/
Fixed::Fixed()
{
	std::cout << GREEN << "Default " << RESET << "constructor called" << std::endl;
	rawBits = 0;
}
/*--------------------------------------------------------*/
/*-----				Copy Constructor				 -----*/
Fixed::Fixed(const Fixed &obj)
{
	std::cout << GREEN << "Copy " << RESET << "constructor called" << std::endl;
	rawBits = obj.getRawBits();
}
/*--------------------------------------------------------*/
/*-----				Assignment Operator				 -----*/
Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << GREEN << "Copy assignment " << RESET << "operator called" << std::endl;
	rawBits = obj.getRawBits();
	return *this;
}
/*--------------------------------------------------------*/
/*-----				Setters/Getters					 -----*/
void	Fixed::setRawBits(int const raw)
{
	rawBits = raw;
}
int		Fixed::getRawBits(void) const
{
	std::cout << GREEN << "getRawBits " << RESET << "member function called" << std::endl;
	return rawBits;
}
/*--------------------------------------------------------*/
/*-----				Destructor						 -----*/
Fixed::~Fixed()
{
	std::cout << RED << "Destructor " << RESET << "called" << std::endl;
}
/*--------------------------------------------------------*/
