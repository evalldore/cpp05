#include <iostream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery", 145, 137) {
	std::cout << "Shrubbery creation form default constructor!" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "Shubbery creation form default destructor!" << std::endl;
}

bool ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const {
	if (!AForm::execute(bureaucrat))
		return false;
	std::cout << "epic shrub" << std::endl;
	return true;
}