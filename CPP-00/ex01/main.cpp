#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	book;
	std::string	input;
	int			i;

	i = 0;
	std::cout << "Enter a command to begin (ADD, SEARCH, EXIT) : ";
	while (std::getline(std::cin, input))
	{
		if (!input.compare("EXIT"))
		{
			std::cout << GREEN << "Exiting Phonebook ... " << RESET << std::endl;
			break;
		}
		else if (!input.compare("ADD"))
		{
			if (i > 7)
				i = 0;
			if (book.add_contact(i))
				return (1);
			i++;
		}
		else if (!input.compare("SEARCH"))
			book.search_contact();
		std::cout << "Enter a command to begin (ADD, SEARCH, EXIT) : ";
	}
	return (0);
}
