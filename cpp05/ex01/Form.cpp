#include "Form.hpp"

Form::~Form()
{
	std::cout << "Form " << _name << " destroyed" << std::endl;
}
Form::Form()
{
	std::cout << "Form " << _name << " created" << std::endl;
	_signed = false;
	_gradeToSign = 150;
	_gradeToExecute = 150;
}
Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	this->_gradeToSign = gradeToSign;
	this->_gradeToExecute = gradeToExecute;
	_signed = false;
	std::cout << "Form " << _name << " created" << std::endl;
}

Form::Form(Form const &other)
{
	*this = other;
}
Form &Form::operator=(Form const &other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
		this->_gradeToSign = other._gradeToSign;
		this->_gradeToExecute = other._gradeToExecute;
	}
	return *this;
}

std::string Form::getName() const
{
	return _name;
}
bool Form::isSigned() const
{
	return _signed;
}
int Form::getGradeToSign() const
{
	return _gradeToSign;
}
int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}
void Form::beSigned(Bureaucrat &b)
{
	if (_signed)
	{
		std::cout << _name << " is already signed" << std::endl;
		return;
	}
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
	std::cout << b.getName() << " signs " << _name << std::endl;
}
std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form Name: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
	   << ", Grade to Sign: " << form.getGradeToSign()
	   << ", Grade to Execute: " << form.getGradeToExecute();
	return os;
}