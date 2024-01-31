#include <iostream>
#include "Form.hpp"

//might be against the subject

static unsigned int validateGrade(unsigned int grade)
{
	if (grade > 150)
	{
		throw Form::GradeTooLowException();
		return 150;
	}
	else if (grade < 1)
	{
		throw Form::GradeTooHighException();
		return 1;
	}
	return grade;
}

//constructors/destructors

Form::Form(void): _name("No Name"), _signGrade(150), _execGrade(150) {
	_signed = false;
	std::cout << "Default form constructor" << std::endl;
}

Form::Form(const std::string name, const unsigned int signGrade = 150, const unsigned int execGrade = 150): _name(name), _signGrade(validateGrade(signGrade)), _execGrade(validateGrade(execGrade)) {
	_signed = false;
	std::cout << *this << std::endl;
}

Form::Form(const Form& other): _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	_signed = false;
	std::cout << "Form copy constructor" << std::endl;
}

Form::~Form(void) {
	std::cout << "Form destructor" << std::endl;
}

//methods

bool Form::isSigned(void) const {
	return _signed;
}

const std::string Form::getName() const {
	return _name;
}

unsigned int Form::getSignGrade() const {
	return _signGrade;
}

unsigned int Form::getExecGrade() const {
	return _execGrade;
}

const Form&	Form::operator=(const Form& other) {
	if (this == &other) return *this;
	_signed = other._signed;
	return *this;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
	{
		throw GradeTooLowException();
		return;
	}
	_signed = true;
}

//exceptions

const char* Form::GradeTooHighException::what(void) const throw() {
	return "Grade too high";
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return "Grade too low";
}

//operators

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << "Form named " << form.getName() << " requiring to sign a grade of " << form.getSignGrade() << " and a grade to execute it of " << form.getExecGrade();
	return out;
}
