#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	_type = src._type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow meow 🐈" << std::endl;
}