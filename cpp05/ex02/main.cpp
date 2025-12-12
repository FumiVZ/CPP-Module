#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

void testRobotomyRequestForm()
{
	Bureaucrat highGradeBureaucrat("Bob", 1);
	Bureaucrat lowGradeBureaucrat("Charlie", 150);
	RobotomyRequestForm form("Robot");

	Bureaucrat justBelowSignGrade("David", 73);
	try
	{
		std::cout << "David (grade 73) attempting to sign the form..." << std::endl;
		justBelowSignGrade.signAForm(form);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	Bureaucrat SignGrade("Eve", 72);
	try
	{
		std::cout << "Eve (grade 72) attempting to sign the form..." << std::endl;
		SignGrade.signAForm(form);
		std::cout << form << std::endl;

		std::cout << "Executing the form..." << std::endl;
		highGradeBureaucrat.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void testShrubberyCreationForm()
{
	Bureaucrat highGradeBureaucrat("Alice", 1);
	Bureaucrat lowGradeBureaucrat("Bob", 150);
	ShrubberyCreationForm form("Garden");

	Bureaucrat justBelowSignGrade("Charlie", 146);
	try
	{
		std::cout << "Charlie (grade 146) attempting to sign the form..." << std::endl;
		justBelowSignGrade.signAForm(form);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	Bureaucrat justAboveSignGrade("David", 144);
	try
	{
		std::cout << "David (grade 144) attempting to sign the form..." << std::endl;
		justAboveSignGrade.signAForm(form);
		std::cout << form << std::endl;

		std::cout << "Executing the form..." << std::endl;
		highGradeBureaucrat.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void testPresidentialPardonForm()
{
	Bureaucrat highGradeBureaucrat("Alice", 1);
	Bureaucrat lowGradeBureaucrat("Bob", 150);
	PresidentialPardonForm form("Zafod");

	Bureaucrat justBelowSignGrade("Charlie", 26);
	try
	{
		std::cout << "Charlie (grade 26) attempting to sign the form..." << std::endl;
		justBelowSignGrade.signAForm(form);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	Bureaucrat justAboveSignGrade("David", 24);
	try
	{
		std::cout << "David (grade 24) attempting to sign the form..." << std::endl;
		justAboveSignGrade.signAForm(form);
		std::cout << form << std::endl;

		std::cout << "Executing the form..." << std::endl;
		highGradeBureaucrat.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

int main(void)
{
	testShrubberyCreationForm();
	testRobotomyRequestForm();
	testPresidentialPardonForm();
	return 0;
}