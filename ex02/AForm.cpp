#include <iostream>
#include "AForm.hpp"

//might be against the subject

static unsigned int validateGrade(unsigned int grade)
{
	if (grade > 150)
	{
		throw AForm::GradeTooLowException();
		return 150;
	}
	else if (grade < 1)
	{
		throw AForm::GradeTooHighException();
		return 1;
	}
	return grade;
}

//constructors/destructors

AForm::AForm(void): _name("No Name"), _signGrade(150), _execGrade(150) {
	_signed = false;
	std::cout << "Default AForm constructor" << std::endl;
}

AForm::AForm(const std::string name, const unsigned int signGrade = 150, const unsigned int execGrade = 150): _name(name), _signGrade(validateGrade(signGrade)), _execGrade(validateGrade(execGrade)) {
	_signed = false;
	std::cout << *this << std::endl;
}

AForm::AForm(const AForm& other): _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	_signed = false;
	std::cout << "AForm copy constructor" << std::endl;
}

AForm::~AForm(void) {
	std::cout << "AForm destructor" << std::endl;
}

//methods

void AForm::execute(const Bureaucrat& Bureaucrat) const {
	if (!_signed)
		throw SignedException();
	else if (Bureaucrat.getGrade() > _execGrade)
		throw GradeTooLowException();
}

bool AForm::isSigned(void) const {
	return _signed;
}

const std::string AForm::getName() const {
	return _name;
}

unsigned int AForm::getSignGrade() const {
	return _signGrade;
}

unsigned int AForm::getExecGrade() const {
	return _execGrade;
}

const AForm& AForm::operator=(const AForm& other) {
	if (this == &other) return *this;
	_signed = other._signed;
	return *this;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
	{
		throw GradeTooLowException();
		return;
	}
	_signed = true;
}

//exceptions

const char* AForm::GradeTooHighException::what(void) const throw() {
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what(void) const throw() {
	return "Grade too low";
}

const char* AForm::SignedException::what(void) const throw() {
	return "Not signed";
}

//operators

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
	out << "AForm named " << AForm.getName() << " requiring to sign a grade of " << AForm.getSignGrade() << " and a grade to execute it of " << AForm.getExecGrade();
	return out;
}
