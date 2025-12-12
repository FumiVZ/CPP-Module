#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;	
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	_type = src._type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof woof 🐕" << std::endl;
}
