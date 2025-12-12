#include "Bureaucrat.hpp"

int main(void)
{
	std::string name = "Bureaucrat";
	Bureaucrat b1(name, 1);
	std::cout << b1 << std::endl;
	try
	{
		b1.IncrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b1 << std::endl;
	b1.DecrementGrade();
	std::cout << b1 << std::endl;
	Bureaucrat b2(name, 150);
	std::cout << b2 << std::endl;
	try
	{
		b2.DecrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b2 << std::endl;
	b2.IncrementGrade();
	std::cout << b2 << std::endl;
	try
	{
		Bureaucrat b3(name, 0);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b4(name, 151);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}