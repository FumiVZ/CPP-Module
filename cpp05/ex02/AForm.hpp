#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;

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
	virtual ~AForm();
	AForm();
	AForm(std::string const &name, int gradeToSign, int gradeToExecute);
	AForm(AForm const &other);
	AForm &operator=(AForm const &other);
	std::string getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	virtual void beSigned(Bureaucrat &executor);
	virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif