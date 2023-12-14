#ifndef	FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"

class Fixed
{
	private:
		int					rawBits;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed &obj);
		// int		toInt(void);
		// float	toFloat(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed	&operator=(const Fixed &obj);
		~Fixed();
};

std::ostream	&operator<<(std::ostream &os, const Fixed &obj);

#endif
