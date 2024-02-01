#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery Creation", target, 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form) : AForm(form) {}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

bool ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const {
	if (!AForm::execute(bureaucrat))
		return false;
	//std::cout << "epic shrub on target " << getTarget() << std::endl;

	std::fstream fs;
	std::string	path = getTarget() + "_shrubbery";

	fs.open(path.c_str(), std::fstream::out | std::fstream::trunc);
	if (!fs.good())
	{
		std::cerr << "Error opening target file " << path << std::endl;
		return false;
	}
	fs <<
	"   *\n"
	"  * *\n"
	" *___*\n"
	" *   *\n";
	return true;
}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form) {
	if (this == &form) return (*this);
	*this = form;
	return (*this);
}