#ifndef CONTACT_HPP
# define CONTACT_HPP

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

#endif
