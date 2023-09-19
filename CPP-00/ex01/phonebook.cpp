/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:29:13 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/19 02:51:05 by mbachar          ###   ########.fr       */
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
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name| Nick Name|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (i < reference)
	{
		std::cout << "|" << "         " << i << "|";
		if (book.contacts[i].firstNameGetter().length() > 9)
			std::cout << book.contacts[i].firstNameGetter().substr(0, 9) + ".";
		else
			std::cout << book.contacts[i].firstNameGetter() << std::setw(10);
		if (book.contacts[i].lastNameGetter().length() > 9)
			std::cout << "|" << book.contacts[i].lastNameGetter().substr(0, 9) + ".";
		else
			std::cout << "|" << book.contacts[i].lastNameGetter() << std::setw(10);
		if (book.contacts[i].nickNameGetter().length() > 9)
			std::cout << "|" << book.contacts[i].nickNameGetter().substr(0, 9) + ".";
		else
			std::cout << "|" << book.contacts[i].nickNameGetter() << std::setw(10);
		std::cout << "|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		i++;
	}
	while (index < 0 || index > i || index > 7) // Check if index is a digit or not
	{
		std::cout << "Index must range between (0 - 7)"; // use getline and atoi on index
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
	PhoneBook	book;
	std::string			input;
	int					i;

	i = 0;
	std::cout << "Enter a command to begin (ADD, SEARCH, EXIT) : ";
	while (true)
	{
		if (!std::getline(std::cin, input))
			exit (1);
		else if (!input.compare("EXIT"))
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
		std::cout << "Enter a command to begin (ADD, SEARCH, EXIT) : ";
	}
	return (0);
}
