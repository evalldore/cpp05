#include <iostream>
#include "Bureaucrat.hpp"

//Constructors/Destructors

Bureaucrat::Bureaucrat(void): _name("No name"), _grade(150) {
	std::cout << "Bureaucrat default constructor!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade): _name(name) {
	_setGrade(grade);
	std::cout << "Bureaucrat constructed with name " << name << " and grade " << _grade << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat default destructor!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	std::cout << "Bureaucrat copy constructor!" << std::endl;
	*this = other;
}

//Methods

const std::string Bureaucrat::getName(void) const {
	return (_name);
}

unsigned int Bureaucrat::getGrade(void) const {
	return (_grade);
}

void Bureaucrat::addGrade(unsigned int amount) {
	_setGrade(_grade - amount);
}

void Bureaucrat::subGrad(unsigned int amount) {
	_setGrade(_grade + amount);
}

void Bureaucrat::_setGrade(unsigned int grade) {
	if (grade > 150)
		throw GradeTooHighException();
	else if (grade < 1)
		throw GradeTooLowException();
	else
		_grade = grade;
}

//Operators

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this == &other) return *this;
	_grade = other.getGrade();
	std::cout << "Bureaucrat copy operator!" << std::endl;
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other)
{
	out << other.getName() << ',' << " bureaucrat grade " << other.getGrade();
	return out;
}

//exceptions

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "Grade too low";
}