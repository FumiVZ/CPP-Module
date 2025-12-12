#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	int _gradeToSign;
	int _gradeToExecute;

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
	~Form();
	Form();
	Form(std::string const &name, int gradeToSign, int gradeToExecute);
	Form(Form const &other);
	Form &operator=(Form const &other);
	std::string getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat &b);
	friend std::ostream &operator<<(std::ostream &os, const Form &form);
};

#endif