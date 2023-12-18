#include "Fixed.hpp"

const int	Fixed::fractionalBits = 8;

/*-----				Default Constructors			-----*/
Fixed::Fixed()
{
	// std::cout << GREEN << " * Default " << RESET << "constructor called" << std::endl;
	rawBits = 0;
}
Fixed::Fixed(const int number)
{
	// std::cout << GREEN << " * Int " << RESET << "constructor called" << std::endl;
	rawBits = number << fractionalBits;
}
Fixed::Fixed(const float number)
{
	// std::cout << GREEN << " * Float " << RESET << "constructor called" << std::endl;
	rawBits = (int)roundf(number * pow(2, 8));
}
/*--------------------------------------------------------*/
/*-----				Copy Constructor				 -----*/
Fixed::Fixed(const Fixed &obj)
{
	// std::cout << GREEN << " * Copy " << RESET << "constructor called" << std::endl;
	rawBits = obj.getRawBits();
	*this = obj;
}
/*--------------------------------------------------------*/
/*-----				Int/Float Member Funcs			-----*/
int	Fixed::toInt(void) const
{
	return (rawBits >> fractionalBits);
}
float	Fixed::toFloat(void) const
{
	return (rawBits / pow(2, 8));
}
/*--------------------------------------------------------*/
/*-----				Assignment Operator				 -----*/
Fixed	&Fixed::operator=(const Fixed &obj)
{
	// std::cout << GREEN << " * Copy Assignment " << RESET << "operator called" << std::endl;
	rawBits = obj.getRawBits();
	return *this;
}
/*--------------------------------------------------------*/
/*-----				Setters/Getters					 -----*/
int	Fixed::getRawBits(void) const
{
	return (rawBits);
}
void	Fixed::setRawBits(const int raw)
{
	rawBits = raw;
}
/*--------------------------------------------------------*/
/*-----				Arithmetic Operators			 -----*/
Fixed	Fixed::operator+(const Fixed &obj) const
{
	Fixed	fixed;
	fixed.rawBits = rawBits + obj.rawBits;
	return fixed;
}
Fixed	Fixed::operator-(const Fixed &obj) const
{
	Fixed	fixed;
	fixed.rawBits = rawBits - obj.rawBits;
	return fixed;
}
Fixed	Fixed::operator*(const Fixed &obj) const
{
	Fixed	fixed;
	fixed.rawBits = rawBits * obj.toFloat();
	return fixed;
}
Fixed	Fixed::operator/(const Fixed &obj) const
{
	Fixed	fixed;
	fixed.rawBits = rawBits / obj.toFloat();
	return fixed;
}
/*--------------------------------------------------------*/
/*-----				Increment/Decrement Operators	 -----*/
Fixed &Fixed::operator++()
{
    this->rawBits++;
    return *this;
}
Fixed &Fixed::operator--()
{
    this->rawBits--;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed fixed = *this;
       
    this->rawBits++;
    return (fixed);
}
Fixed Fixed::operator--(int)
{
    Fixed fixed = *this;

    this->rawBits--;
    return fixed;
}
/*--------------------------------------------------------*/
/*-----				Comparison Operators			 -----*/
bool	Fixed::operator==(const Fixed &obj) const
{
	return rawBits == obj.rawBits ? true : false;
}
bool	Fixed::operator!=(const Fixed &obj) const
{
	return rawBits != obj.rawBits ? true : false;
}
bool	Fixed::operator>(const Fixed &obj) const
{
	return rawBits > obj.rawBits ? true : false;
}
bool	Fixed::operator<(const Fixed &obj) const
{
	return rawBits < obj.rawBits ? true : false;
}
bool	Fixed::operator>=(const Fixed &obj) const
{
	return rawBits >= obj.rawBits ? true : false;
}
bool	Fixed::operator<=(const Fixed &obj) const
{
	return rawBits <= obj.rawBits ? true : false;
}
/*--------------------------------------------------------*/
/*-----				Max/Min Member Funcs			 -----*/
Fixed	&Fixed::min(Fixed &x, Fixed &y)
{
	return x > y ? y : x;
}
Fixed	&Fixed::max(Fixed &x, Fixed &y)
{
	return x > y ? x : y;
}
Fixed	const &Fixed::min(const Fixed &x, const Fixed &y)
{
	return x > y ? y : x;
}
Fixed	const &Fixed::max(const Fixed &x, const Fixed &y)
{
	return x > y ? x : y;
}
/*--------------------------------------------------------*/
/*-----				Destructor						 -----*/
Fixed::~Fixed()
{
	// std::cout << RED << " * Destructor " << RESET << "called" << std::endl;
}
/*--------------------------------------------------------*/
/*-----				Insertion Operator				 -----*/
std::ostream	&operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return os;
}
/*--------------------------------------------------------*/
