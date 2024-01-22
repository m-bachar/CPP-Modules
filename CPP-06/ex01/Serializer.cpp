#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << GREEN << " * Serializer " << RESET << "default constructor called !" << std::endl;
}

Serializer::Serializer(const Serializer &obj)
{
	(void)obj;
}

Serializer	&Serializer::operator=(const Serializer &obj)
{
	(void)obj;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t tbr = reinterpret_cast<uintptr_t>(ptr);
	return tbr;
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	Data *tbr = reinterpret_cast<Data *>(raw);
	return tbr;
}

Serializer::~Serializer()
{
	std::cout << RED << " * Serializer " << RESET << "destructor called !" << std::endl;
}
