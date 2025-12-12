#include "Intern.hpp"
#include <iostream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &other)
{
	*this = other;
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
	int i = -1;
	std::string requestForms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	while (++i < 3)
	{
		if (formName == requestForms[i])
			break;
	}
	switch (i)
	{
	case 0:
		std::cout << "Intern creates " << formName << std::endl;
		return new RobotomyRequestForm(target);
	case 1:
		std::cout << "Intern creates " << formName << std::endl;
		return new ShrubberyCreationForm(target);
	case 2:
		std::cout << "Intern creates " << formName << std::endl;
		return new PresidentialPardonForm(target);
	default:
		std::cout << "Intern does not know how to create " << formName << std::endl;
		break;
	}
	return NULL;
}
