#include "AForm.hpp"

AForm::~AForm()
{
}
AForm::AForm() : _name("default"), _gradeToSign(1), _gradeToExecute(1)
{
	_signed = false;
}
AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	_signed = false;
	std::cout << "AForm " << _name << " created" << std::endl;
}

AForm::AForm(AForm const &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	*this = other;
}
AForm &AForm::operator=(AForm const &other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}
std::string AForm::getName() const
{
	return _name;
}
bool AForm::isSigned() const
{
	return _signed;
}
int AForm::getGradeToSign() const
{
	return _gradeToSign;
}
int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat &b)
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

void AForm::execute(Bureaucrat const &executor) const
{
	if (!_signed)
		throw std::runtime_error("Form is not signed");
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form Name: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
	   << ", Grade to Sign: " << form.getGradeToSign()
	   << ", Grade to Execute: " << form.getGradeToExecute();
	return os;
}