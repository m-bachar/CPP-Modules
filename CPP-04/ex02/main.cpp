#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	func()
{
	system("leaks Brain");
}

int main()
{
	atexit(func);
	Animal	*animalo[N];
	int		i = 0;

	while (i < N / 2)
	{
		animalo[i] = new Cat();
		i++;
	}
	while (i < N)
	{
		animalo[i] = new Dog();
		i++;
	}
	i = 0;
	while (i < N)
	{
		delete animalo[i];
		i++;
	}
	return 0;
}
