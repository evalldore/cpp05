#include <iostream>
#include "Bureaucrat.hpp"

//Constructors/Destructors

Bureaucrat::Bureaucrat(void): _name("None"), _grade(0) {
	std::cout << "Bureaucrat default constructor!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, uint32_t grade): _name(name), _grade(grade) {
	std::cout << "Bureaucrat constructed with name " << name << " and grade " << grade << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucraft default destructor!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	std::cout << "Bureaucrat copy constructor!" << std::endl;
	*this = other;
}

//Methods

const std::string Bureaucrat::getName(void) const {
	return (_name);
}

uint32_t Bureaucrat::getGrade(void) const {
	return (_grade);
}

//Operators

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this == &other) return *this;
	std::cout << "Bureaucrat copy operator!" << std::endl;
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other)
{
	out << other.getName() << ',' << " bureaucrat grade " << other.getGrade();
	return out;
}