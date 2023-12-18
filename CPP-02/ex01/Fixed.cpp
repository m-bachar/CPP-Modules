#include "Fixed.hpp"

const int	Fixed::fractionalBits = 8;

/*-----				Default Constructors			-----*/
Fixed::Fixed()
{
	std::cout << GREEN << " * Default " << RESET << "constructor called" << std::endl;
	rawBits = 0;
}
Fixed::Fixed(const int number)
{
	std::cout << GREEN << " * Int " << RESET << "constructor called" << std::endl;
	rawBits = number << fractionalBits;
}
Fixed::Fixed(const float number)
{
	std::cout << GREEN << " * Float " << RESET << "constructor called" << std::endl;
	rawBits = (int)roundf(number * pow(2, 8));
}
/*--------------------------------------------------------*/
/*-----				Copy Constructor				 -----*/
Fixed::Fixed(const Fixed &obj)
{
	std::cout << GREEN << " * Copy " << RESET << "constructor called" << std::endl;
	rawBits = obj.getRawBits();
	*this = obj;
}
/*--------------------------------------------------------*/
/*-----				Assignment Operator				 -----*/
Fixed	&Fixed::operator=(const Fixed &obj)
{
	std::cout << GREEN << " * Copy Assignment " << RESET << "operator called" << std::endl;
	rawBits = obj.getRawBits();
	return *this;
}
/*--------------------------------------------------------*/
/*-----				Int/Float Member Funcs			 -----*/
int	Fixed::toInt(void) const
{
	return (rawBits >> fractionalBits);
}
float	Fixed::toFloat(void) const
{
	return (rawBits / pow(2, 8));
}
/*--------------------------------------------------------*/
/*-----				Setters/Getters					 -----*/
void	Fixed::setRawBits(const int raw)
{
	rawBits = raw;
}
int	Fixed::getRawBits(void) const
{
	return (rawBits);
}
/*--------------------------------------------------------*/
/*-----				Destructor						 -----*/
Fixed::~Fixed()
{
	std::cout << RED << " * Destructor " << RESET << "called" << std::endl;
}
/*--------------------------------------------------------*/
/*-----				Insertion Operator				 -----*/
std::ostream	&operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return os;
}
/*--------------------------------------------------------*/
