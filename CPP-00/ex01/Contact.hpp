/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benito <benito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:44:08 by benito            #+#    #+#             */
/*   Updated: 2023/09/17 20:45:29 by benito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

public:
	/*			Getters			*/
	std::string	firstNameGetter(void);
	std::string	lastNameGetter(void);
	std::string	nickNameGetter(void);
	std::string	phoneNumberGetter(void);
	std::string	darkestSecretGetter(void);

	/*			Setters			*/
	void		firstNameSetter(std::string);
	void		lastNameSetter(std::string);
	void		nickNameSetter(std::string);
	void		phoneNumberSetter(std::string);
	void		darkestSecretSetter(std::string);
};

/*			Getters			*/
std::string	Contact::firstNameGetter(void)
{
	return (this->firstName);
}

std::string	Contact::lastNameGetter(void)
{
	return (this->lastName);
}

std::string	Contact::nickNameGetter(void)
{
	return (this->nickName);
}

std::string	Contact::phoneNumberGetter(void)
{
	return (this->phoneNumber);
}

std::string	Contact::darkestSecretGetter(void)
{
	return (this->darkestSecret);
}

/*			Setters			*/
void	Contact::firstNameSetter(std::string firstName)
{
	this->firstName = firstName;
}

void	Contact::lastNameSetter(std::string lastName)
{
	this->lastName = lastName;
}

void	Contact::nickNameSetter(std::string nickName)
{
	this->nickName = nickName;
}

void	Contact::phoneNumberSetter(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void	Contact::darkestSecretSetter(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}
