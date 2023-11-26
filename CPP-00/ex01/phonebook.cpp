/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:29:13 by mbachar           #+#    #+#             */
/*   Updated: 2023/11/26 23:14:27 by mbachar          ###   ########.fr       */
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

	std::cout << " * First Name     : ";
	if (!std::getline(std::cin, firstName) || std::cin.eof() ||!firstName.length()) // .eof??
		exit (1);
	book.contacts[i].firstNameSetter(firstName);
	std::cout << " * Last Name      : ";
	if (!std::getline(std::cin, lastName) || std::cin.eof() || !lastName.length())
		exit (1);
	book.contacts[i].lastNameSetter(lastName);
	std::cout << " * Nickname       : ";
	if (!std::getline(std::cin, nickName) || std::cin.eof() || !nickName.length())
		exit (1);
	book.contacts[i].nickNameSetter(nickName);
	std::cout << " * Phone Number   : ";
	if (!std::getline(std::cin, phoneNumber) || std::cin.eof() || !phoneNumber.length())
		exit (1);
	for (size_t x = 0; x < phoneNumber.length(); x++)
	{
		if (!std::isdigit(phoneNumber[x]))
		{
			std::cout << "Error: Phone number must be composed of digits only !" << std::endl;
			exit (1);
		}
	}
	book.contacts[i].phoneNumberSetter(phoneNumber);
	std::cout << " * Darkest Secret : ";
	if (!std::getline(std::cin, darkestSecret) || std::cin.eof() || !darkestSecret.length())
		exit (1);
	book.contacts[i].darkestSecretSetter(darkestSecret);
}

void	search_contact(PhoneBook &book, int size)
{
	int			i;
	int			index;
	std::string	index_str;

	i = 0;
	index = -1;
	// size = 0; // to be changed
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (i < size)
	{
		std::cout << "|" << "         " << i << "|";
		if (book.contacts[i].firstNameGetter().length() > 9)
			std::cout << book.contacts[i].firstNameGetter().substr(0, 9) + ".";
		else
			std::cout  << std::setw(10) << book.contacts[i].firstNameGetter();
		if (book.contacts[i].lastNameGetter().length() > 9)
			std::cout << "|" << book.contacts[i].lastNameGetter().substr(0, 9) + ".";
		else
			std::cout << "|" << std::setw(10) << book.contacts[i].lastNameGetter();
		if (book.contacts[i].nickNameGetter().length() > 9)
			std::cout << "|" << book.contacts[i].nickNameGetter().substr(0, 9) + ".";
		else
			std::cout << "|" << std::setw(10) << book.contacts[i].nickNameGetter();
		std::cout << "|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		i++;
	}
	
}

int main(void)
{
	PhoneBook			book;
	std::string			input;
	int					i;

	i = 0;
	while (true)
	{
		std::cout << "Enter a command to begin (ADD, SEARCH, EXIT) : ";
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
	}
	return (0);
}
