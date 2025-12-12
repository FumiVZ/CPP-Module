#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>

void testIntern()
{
	Intern intern;
	Bureaucrat bureaucrat("Alice", 1);

	try
	{
		AForm *shrubberyForm = intern.makeForm("shrubbery creation", "Garden");
		std::cout << "Created form: " << *shrubberyForm << std::endl;
		bureaucrat.signAForm(*shrubberyForm);
		bureaucrat.executeForm(*shrubberyForm);
		delete shrubberyForm;

		AForm *robotomyForm = intern.makeForm("robotomy request", "Robot");
		std::cout << "Created form: " << *robotomyForm << std::endl;
		bureaucrat.signAForm(*robotomyForm);
		bureaucrat.executeForm(*robotomyForm);
		delete robotomyForm;

		AForm *pardonForm = intern.makeForm("presidential pardon", "Zafod");
		std::cout << "Created form: " << *pardonForm << std::endl;
		bureaucrat.signAForm(*pardonForm);
		bureaucrat.executeForm(*pardonForm);
		delete pardonForm;
		AForm *unknownForm = intern.makeForm("unknown form", "Target");
		delete unknownForm;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

int main()
{
	testIntern();
	return 0;
}