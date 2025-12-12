#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	this->brain = new Brain();
	std::cerr << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &src)
{
	std::cerr << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*src.brain);
	*this = src;
}

Cat::~Cat(void)
{
	delete brain;
	std::cerr << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cerr << "Cat assignation operator called" << std::endl;
	if (this != &src)
	{
		delete brain;
		brain = new Brain(*src.brain);
		_type = src._type;
	}
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow meow 🐈" << std::endl;
}
