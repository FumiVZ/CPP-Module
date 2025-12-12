#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
	const Animal* animals[20];

	for (int i = 0; i < 10; i++)
	{
		animals[i] = new Dog();
		animals[i]->makeSound();
	}
	for (int i = 10; i < 20; i++)
	{
		animals[i] = new Cat();
		animals[i]->makeSound();
	}
	for (int i = 0; i < 20; i++)
	{
		delete animals[i];
	}
	i->makeSound();
	j->makeSound();
    delete i;
    delete j;
    return 0;
}