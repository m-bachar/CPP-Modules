#pragma once

#include <iostream>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

struct Data
{
	std::string	login;
	std::string	password;
	int			age;
};

class Serializer
{
	private:
		Serializer();
	public:
		Serializer(const Serializer &obj);
		Serializer &operator=(const Serializer &obj);
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
		~Serializer();
};
