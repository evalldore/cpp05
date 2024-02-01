#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


//constructor/destructor

Intern::Intern(void) {
	std::cout << "Intern default constructor!" << std::endl;
	_enumMap["shrubby creation"] = SHRUBBY;
	_enumMap["presidential pardon"] = PRESIDENTIAL;
	_enumMap["robotomy request"] = ROBOTOMY;
}

Intern::Intern(const Intern& intern) {
	(void)intern;
	std::cout << "Intern copy constructor!" << std::endl;
	_enumMap["shrubby creation"] = SHRUBBY;
	_enumMap["presidential pardon"] = PRESIDENTIAL;
	_enumMap["robotomy request"] = ROBOTOMY;
}

Intern::~Intern(void) {
	std::cout << "Intern default destructor!" << std::endl;
}

//methods

AForm* Intern::makeForm(const std::string name, const std::string target) {
	int formEnum = _enumMap[name];
	AForm* formPtr = NULL;

	switch (formEnum) {
		case PRESIDENTIAL: formPtr = new PresidentialPardonForm(target); break;
		case ROBOTOMY: formPtr = new RobotomyRequestForm(target); break;
		case SHRUBBY: formPtr = new ShrubberyCreationForm(target); break;
		default : formPtr = NULL;
	}
	if (formPtr)
		std::cout << "Intern creates " << *formPtr << std::endl;
	else
		std::cout << name << " is not a valid form name" << std::endl;
	return formPtr;
}

//operator

const Intern& Intern::operator=(const Intern& other) {
	if (this == &other) return *this;
	*this = other;
	return (*this);
}
