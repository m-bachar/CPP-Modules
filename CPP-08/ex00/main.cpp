#include "easyfind.hpp"

int main()
{
	/*	Vector	*/
	std::vector<int> arr;
	arr.push_back(106);
	arr.push_back(105);
	arr.push_back(104);
	arr.push_back(103);
	arr.push_back(102);
	arr.push_back(101);
	arr.push_back(100);
	arr.push_back(99);
	arr.push_back(98);
	arr.push_back(97);
	arr.push_back(96);
	std::vector<int>::iterator it;

	std::cout << GREEN << " * Vector : " << RESET;
	for (it = arr.begin(); it < arr.end(); it++)
		std::cout << static_cast<int>(*it) << " ";
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
	std::list<int> lst;
	std::list<int>::iterator it_;

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
