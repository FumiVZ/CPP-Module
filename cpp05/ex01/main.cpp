#include "Bureaucrat.hpp"

int main(void)
{
	std::string name = "Bureaucrat";
	Bureaucrat b1(name, 1);
	Bureaucrat b2(name, 150);

	Form f1("Form1", 1, 1);
	Form f2("Form2", 150, 150);

	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;

	b1.signForm(f1);
	b2.signForm(f2);
	b2.signForm(f1);

	return 0;
}