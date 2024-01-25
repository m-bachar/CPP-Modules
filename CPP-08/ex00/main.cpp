#include "easyfind.hpp"

int main()
{
	/*	Arrays	*/
	std::array<char, N> arr = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106};
	std::array<char, N>::iterator it;

	std::cout << GREEN << " * Array : " << RESET;
	for (it = arr.begin(); it < arr.end(); it++)
		std::cout << static_cast<char>(*it) << " ";
	std::cout << std::endl;
	try
	{
		std::cout << static_cast<char>(::easyfind(arr, 102)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << " * Error : " << RESET << e.what() << std::endl;
	}

	/*	Lists	*/
	std::list<char> lst;
	std::list<char>::iterator it_;

	for (int i = 97; i < 107; i++)
		lst.push_back(i);
	std::cout << GREEN << " * List  : " << RESET;
	for (it_ = lst.begin(); it_ != lst.end(); it_++)
	    std::cout << *it_ << " ";
	std::cout << std::endl;
	try
	{
		std::cout << static_cast<char>(::easyfind(arr, 102)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << " * Error : " << RESET << e.what() << std::endl;
	}
}
