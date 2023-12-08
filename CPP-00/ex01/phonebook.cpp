#include "PhoneBook.hpp"

void ft_error(std::string error)
{
	std::cout << RED << "Error : " << RESET << error << std::endl;
}

int PhoneBook::add_contact(int i)
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	int			phone_flag = 0;

	while (1)
	{
		std::cout << " * First Name     : ";
		if (!std::getline(std::cin, firstName))
			return (1);
		if (std::cin.eof() || !firstName.length())
			ft_error("Invalid input ! Try again !");
		else
		{
			contacts[i].firstNameSetter(firstName);
			break ;
		}
	}
	while (1)
	{
		std::cout << " * Last Name      : ";
		if (!std::getline(std::cin, lastName))
			return (1);
		if (std::cin.eof() || !lastName.length())
			ft_error("Invalid input ! Try again !");
		else
		{
			contacts[i].lastNameSetter(lastName);
			break ;
		}
	}
	while (1)
	{
		std::cout << " * Nickname       : ";
		if (!std::getline(std::cin, nickName))
			return (1);
		if (std::cin.eof() || !nickName.length())
			ft_error("Invalid input ! Try again !");
		else
		{
			contacts[i].nickNameSetter(nickName);
			break ;
		}
	}
	while (1)
	{
		std::cout << " * Phone Number   : ";
		if (!std::getline(std::cin, phoneNumber))
			return (1);
		if (std::cin.eof() || !phoneNumber.length())
			ft_error("Invalid input ! Try again !");
		else
		{
			phone_flag = 0;
			for (size_t x = 0; x < phoneNumber.length(); x++)
			{
				if (!std::isdigit(phoneNumber[x]))
				{
					ft_error("Phone number must be composed of digits only !");
					phone_flag = 1;
					break ;
				}
			}
			if (phone_flag == 0)
			{
				contacts[i].phoneNumberSetter(phoneNumber);
				break ;
			}
		}
	}
	while (1)
	{
		std::cout << " * Darkest Secret : ";
		if (!std::getline(std::cin, darkestSecret))
			return (1);
		if (std::cin.eof() || !darkestSecret.length())
			ft_error("Invalid input ! Try again !");
		else
		{
			contacts[i].darkestSecretSetter(darkestSecret);
			break ;
		}
	}
	return (0);
}

int PhoneBook::search_contact(void)
{
	int i;
	int index;
	std::string index_str;

	i = 0;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	while (i < 8)
	{
		std::cout << "|"
				  << "         " << i << "|";
		if (contacts[i].firstNameGetter().length() > 10)
			std::cout << contacts[i].firstNameGetter().substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << contacts[i].firstNameGetter();
		if (contacts[i].lastNameGetter().length() > 10)
			std::cout << "|" << contacts[i].lastNameGetter().substr(0, 9) + ".";
		else
			std::cout << "|" << std::setw(10) << contacts[i].lastNameGetter();
		if (contacts[i].nickNameGetter().length() > 10)
			std::cout << "|" << contacts[i].nickNameGetter().substr(0, 9) + ".";
		else
			std::cout << "|" << std::setw(10) << contacts[i].nickNameGetter();
		std::cout << "|" << std::endl;
		std::cout << "+----------+----------+----------+----------+" << std::endl;
		i++;
	}
	std::cout << "Enter contact's index : ";
	if (!std::getline(std::cin, index_str))
		return (1);
	if (!index_str.compare(""))
		return (ft_error("Invalid input ! Try again !"), 1);
	else
	{
		for (size_t i = 0; i < index_str.length(); i++)
		{
			if (!std::isdigit(index_str[i]))
			{
				ft_error("Index must be a number between 0 and 7 !");
				return (1);
			}
		}
		index = std::atoi(index_str.c_str());
		if (index < 0 || index > 7)
		{
			ft_error("Index must be a number between 0 and 7 !");
			return (1);
		}
		else if (!contacts[index].firstNameGetter().length())
		{
			ft_error("Index must be a number between 0 and 7 !");
			return (1);
		}
	}
	std::cout << GREEN << "First Name     : " << RESET << contacts[index].firstNameGetter() << std::endl;
	std::cout << GREEN << "Last Name      : " << RESET << contacts[index].lastNameGetter() << std::endl;
	std::cout << GREEN << "NickName       : " << RESET << contacts[index].nickNameGetter() << std::endl;
	std::cout << GREEN << "Phone Number   : " << RESET << contacts[index].phoneNumberGetter() << std::endl;
	std::cout << GREEN << "Darkest Secret : " << RESET << contacts[index].darkestSecretGetter() << std::endl;
	return (0);
}
