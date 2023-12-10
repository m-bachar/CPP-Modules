#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "Contact.hpp"

#define RESET     "\x1b[0m"
#define GREEN     "\x1b[1;32m"
#define RED       "\x1b[1;31m"

class PhoneBook
{
	private:
		Contact		contacts[8];
	public:
		int	add_contact(int i);
		int	search_contact();
};

#endif
