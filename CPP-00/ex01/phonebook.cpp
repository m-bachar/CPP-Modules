/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benito <benito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:29:13 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/17 21:37:25 by benito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	add_contact(PhoneBook &book, int i)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << "First Name     : ";
	if (!std::getline(std::cin, firstName) || !firstName.length())
		exit (1);
	book.contacts[i].firstNameSetter(firstName);
	std::cout << "Last Name      : ";
	if (!std::getline(std::cin, lastName) || !lastName.length())
		exit (1);
	book.contacts[i].lastNameSetter(lastName);
	std::cout << "Nick Name      : ";
	if (!std::getline(std::cin, nickName) || !nickName.length())
		exit (1);
	book.contacts[i].nickNameSetter(nickName);
	std::cout << "Phone Number   : ";
	if (!std::getline(std::cin, phoneNumber) || !phoneNumber.length()) // phoneNumber must be a mix of digits
		exit (1);
	book.contacts[i].phoneNumberSetter(phoneNumber);
	std::cout << "Darkest Secret : ";
	if (!std::getline(std::cin, darkestSecret) || !darkestSecret.length())
		exit (1);
	book.contacts[i].darkestSecretSetter(darkestSecret);
}

void	search_contact(PhoneBook &book, int reference)
{
	int	i;
	int	index;

	i = 0;
	index = -1;
	std::cout << "|-----------|-----------|-----------|-----------|" << std::endl;
	std::cout << "|      Index| First Name|  Last Name|  Nick Name|" << std::endl;
	std::cout << "|-----------|-----------|-----------|-----------|" << std::endl;
	while (i < reference)
	{
		std::cout << "|" << "          " << i << "|" 
			<< book.contacts[i].firstNameGetter().substr(0, 10) + "." 
			<< "|" << book.contacts[i].lastNameGetter().substr(0, 10) + "." 
			<< "|" << book.contacts[i].nickNameGetter().substr(0, 10) + "." 
			<< "|" << std::endl;
		std::cout << "|-----------|-----------|-----------|-----------|" << std::endl;
		i++;
	}
	while (index < 0 || index > reference) // Check if index is a digit or not
	{
		std::cout << "Index must range between (0 - "
					<< reference << ") : ";
		std::cin >> index;
	}
	std::cout << "First Name     : " << book.contacts[index].firstNameGetter() << std::endl;
	std::cout << "Last Name      : " << book.contacts[index].lastNameGetter() << std::endl;
	std::cout << "Nick Name      : " << book.contacts[index].nickNameGetter() << std::endl;
	std::cout << "Phone Number   : " << book.contacts[index].phoneNumberGetter() << std::endl;
	std::cout << "Darkest Secret : " << book.contacts[index].darkestSecretGetter() << std::endl;
}

int main(void)
{
	static PhoneBook	book;
	std::string			input;
	int					i;

	i = 0;
	while (true)
	{
		std::cout << "Enter a command to begin (ADD, SEARCH, EXIT) : ";
		if (!std::getline(std::cin, input))
			exit (1);
		if (!input.compare("EXIT"))
			break;
		else if (!input.compare("ADD"))
		{
			if (i > 7)
				i = 0;
			add_contact(book, i);
			i++;
		}
		else if (!input.compare("SEARCH"))
			search_contact(book, i);
	}
	return (0);
}
