#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cerr << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cerr << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &srcs)
{
	std::cerr << "Brain copy constructor called" << std::endl;
	*this = srcs;
}

Brain &Brain::operator=(const Brain &srcs)
{
	std::cerr << "Brain assignation operator called" << std::endl;
	if (this != &srcs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = srcs.ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(int index) const
{
	return (this->ideas[index]);
}

void Brain::setIdea(int index, const std::string &idea)
{
	this->ideas[index] = idea;
}
