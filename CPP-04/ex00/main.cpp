#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal* meta = new Animal();
	Animal* j = new Dog();
	Animal* i = new Cat();
	// WrongAnimal* k = new WrongCat();
	// WrongCat* l = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	// std::cout << k->getType() << " " << std::endl;
	// std::cout << l->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	// k->makeSound();
	// l->makeSound();

	delete meta;
	delete i;
	delete j;
	// delete k;
	// delete l;

	return 0;
}
