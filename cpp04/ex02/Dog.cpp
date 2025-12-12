#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	this->brain = new Brain();
	std::cerr << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &src)
{
	std::cerr << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*src.brain);
	*this = src;	
}

Dog::~Dog(void)
{
	delete brain;
	std::cerr << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cerr << "Dog assignation operator called" << std::endl;
	if (this != &src)
	{
		delete brain;
		brain = new Brain(*src.brain);
		_type = src._type;
	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof woof 🐕" << std::endl;
}
