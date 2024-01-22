#include "Serializer.hpp"

int	main(void)
{
	Data* ptr = new Data;
	ptr->login = "mbachar";
	ptr->password = "hh hmimeq";
	ptr->age = 21;

	std::cout << ORANGE << " * Data *ptr Information  : " << RESET << std::endl;
	std::cout << " * Login = " << ptr->login << std::endl;
	std::cout << " * Password = " << ptr->password << std::endl;
	std::cout << " * Age = " << ptr->age << std::endl;

	uintptr_t pkhew = Serializer::serialize(ptr);
	Data *ptr_ = Serializer::deserialize(pkhew);

	std::cout << ORANGE << " * Data *ptr_ Information : " << RESET << std::endl;
	std::cout << " * Login = " << ptr_->login << std::endl;
	std::cout << " * Password = " << ptr_->password << std::endl;
	std::cout << " * Age = " << ptr_->age << std::endl;

	delete ptr;
	return 0;
}
