#pragma once

#include <iostream>
#include <cmath>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"

class Fixed
{
	private:
		int					rawBits;
		static const int	fractionalBits;
	public:
		/*		Default Constructors			*/
		Fixed();
		Fixed(const int		number);
		Fixed(const float	number);
		/*		Copy Constructor				*/
		Fixed(const Fixed &obj);
		/*		toInt/toFloat member Funcs		*/
		int		toInt() const;
		float	toFloat() const;
		/*		Assignment Operator				*/
		Fixed	&operator=(const Fixed &obj);
		/*		Setters/Getters					*/
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		/*		Arithmetic Operators			*/
		Fixed	operator+(const	Fixed &obj) const;
		Fixed	operator-(const	Fixed &obj) const;
		Fixed	operator*(const	Fixed &obj) const;
		Fixed	operator/(const	Fixed &obj) const;
		/*		Increment/Decrement Operators	*/
		Fixed	&operator++();
		Fixed	&operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
		/*		Comparison Operators			*/
		bool	operator==(const Fixed &obj) const;
		bool	operator!=(const Fixed &obj) const;
		bool	operator>(const Fixed &obj) const;
		bool	operator<(const Fixed &obj) const;
		bool	operator>=(const Fixed &obj) const;
		bool	operator<=(const Fixed &obj) const;
		/*		Max/Min Member Funcs			*/
		static Fixed		&min(Fixed &x, Fixed &y);
		static Fixed		&max(Fixed &x, Fixed &y);
		static const Fixed	&min(const Fixed &x, const Fixed &y);
		static const Fixed	&max(const Fixed &x, const Fixed &y);
		/*		Destructor						*/
		~Fixed();
};

std::ostream	&operator<<(std::ostream &os, const Fixed &obj);
