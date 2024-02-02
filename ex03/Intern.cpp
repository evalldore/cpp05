#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


//constructor/destructor

Intern::Intern(void) {
	_formNames[SHRUBBY] = "shrubbery creation";
	_formNames[PRESIDENTIAL] = "presidential pardon";
	_formNames[ROBOTOMY] = "robotomy request";
	std::cout << "Intern default constructor!" << std::endl;
}

Intern::Intern(const Intern& intern) {
	(void)intern;
	_formNames[SHRUBBY] = "shrubbery creation";
	_formNames[PRESIDENTIAL] = "presidential pardon";
	_formNames[ROBOTOMY] = "robotomy request";
	std::cout << "Intern copy constructor!" << std::endl;
}

Intern::~Intern(void) {
	std::cout << "Intern default destructor!" << std::endl;
}

//methods

AForm* Intern::makeForm(const std::string name, const std::string target) {
	AForm* formPtr = NULL;
	for (int index = 0; index < MAX_FORM; index++)
	{
		if (_formNames[index] == name)
		{
			switch (index) {
				case PRESIDENTIAL: formPtr = new PresidentialPardonForm(target); break;
				case ROBOTOMY: formPtr = new RobotomyRequestForm(target); break;
				case SHRUBBY: formPtr = new ShrubberyCreationForm(target); break;
				default : formPtr = NULL;
			}
			break;
		}
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
