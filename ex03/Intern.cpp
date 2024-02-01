#include <iostream>
#include "Intern.hpp"

//constructor/destructor

Intern::Intern(void) {
	std::cout << "Intern default constructor!" << std::endl;
}

Intern::Intern(const Intern& intern) {
	*this = intern;
}

Intern::~Intern(void) {
	std::cout << "Intern default destructor!" << std::endl;
}

//methods

AForm* makeForm(const std::string name, const std::string target) {
	
}

//operator

const Intern& Intern::operator=(const Intern& other) {
	if (this == &other) return *this;
	*this = other;
	return (*this);
}