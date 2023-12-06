#include "PhoneBook.hpp"

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
