#pragma once

#include <iostream>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"

class	Fixed
{
	private:
		int					rawBits;
		static const int	fractionalBits;
	public:
		/*		Default Constructor		*/
		Fixed();
		/*		Copy Constructor		*/
		Fixed(const Fixed &obj);
		/*		Assignment Operator		*/
		Fixed	&operator=(const Fixed &obj);
		/*		Setters/Getters			*/
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		/*		Destructor				*/
		~Fixed();
};
