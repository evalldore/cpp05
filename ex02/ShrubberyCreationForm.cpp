#include <iostream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery Creation", target, 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form) : AForm(form) {}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

bool ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const {
	if (!AForm::execute(bureaucrat))
		return false;
	std::cout << "epic shrub" << std::endl;
	return true;
}