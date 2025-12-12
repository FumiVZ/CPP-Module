#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw() { return "Grade is too low"; }
	};
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw() { return "Grade is too high"; }
	};
	~Bureaucrat();
	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat &operator=(Bureaucrat const &other);
	std::string getName() const;
	int getGrade() const;
	void IncrementGrade();
	void DecrementGrade();
	void signForm(Form &form);
};
#endif