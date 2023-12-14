#include "Fixed.hpp"

// const int	Fixed::fractionalBits = 8;

Fixed	&Fixed::operator=(const Fixed &obj)
{
	std::cout << GREEN << " * Copy Assignment " << RESET << "operator called" << std::endl;
	rawBits = obj.getRawBits();
	return *this;
}

Fixed::Fixed()
{
	std::cout << GREEN << " * Default " << RESET << "constructor called" << std::endl;
	rawBits = 0;
}

Fixed::Fixed(const int number)
{
	(void)number;
	std::cout << GREEN << " * Int " << RESET << "constructor called" << std::endl;
}

Fixed::Fixed(const float number)
{
	(void)number;
	std::cout << GREEN << " * Float " << RESET << "constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << GREEN << " * Copy " << RESET << "constructor called" << std::endl;
	rawBits = obj.getRawBits();
}

int	Fixed::getRawBits(void) const
{
	return (rawBits);
}

void	Fixed::setRawBits(const int raw)
{
	rawBits = raw;
}

std::ostream	&operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.getRawBits();
	return os;
}

Fixed::~Fixed()
{
	std::cout << RED << " * Destructor " << RESET << "called" << std::endl;
}
