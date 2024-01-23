#pragma once

#include <iostream>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

# define N 10

template <typename T>
class Array
{
	private:
		T	*arr;
		unsigned int	size;
	public:
		Array()
		{
			std::cout << GREEN << " * Array " << RESET << "default constructor called !" << std::endl;
			if (N > 0)
			{
				std::cout << RED << " * Error " << RESET << "size must be greater than 0." << std::endl;
				return;
			}
			arr = new T[N];
			size = N;
		}
		Array(unsigned int n)
		{
			std::cout << GREEN << " * Array " << RESET << "parametrized constructor called !" << std::endl;
			if (n <= 0)
			{
				std::cout << RED << " * Error " << RESET << "size must be greater than 0." << std::endl;
				return;
			}
			arr = new T[n];
			size = n;
		}
		Array(const Array &obj)
		{
			*this = obj;
		}
		Array	&operator=(const Array &obj)
		{
			this->arr = obj.arr;
			this->size = obj.size;
			return *this;
		}
		unsigned int	sizeArr()
		{
			return size;
		}
		class OutOfRangeException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "index out of range !";
				}
		};
		T& operator[](unsigned int i)
		{
			if (i >= size)
				throw OutOfRangeException();
			return arr[i];
		}
		const T &operator[](unsigned int i) const
		{
			if (i >= size)
				throw OutOfRangeException();
			return arr[i];
		}
		~Array()
		{
			std::cout << RED << " * Array " << RESET << "destructor called !" << std::endl;
			delete[] arr;
		}
};
