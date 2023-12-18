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
		/*		Default Constructors		*/
		Fixed();
		Fixed(const int		number);
		Fixed(const float	number);
		/*		Copy Constructors			*/
		Fixed(const	Fixed	&obj);
		/*		Assignment Operator			*/
		Fixed	&operator=(const Fixed &obj);
		/*		toInt/toFloat Member Funcs	*/
		int		toInt(void) const;
		float	toFloat(void) const;
		/*		Setters/Getters				*/
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		/*		Destructor					*/
		~Fixed();
};

std::ostream	&operator<<(std::ostream &os, const Fixed &obj);
