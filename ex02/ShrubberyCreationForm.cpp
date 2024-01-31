#include <iostream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery", 145, 137) {
	std::cout << "Shrubbery creation form default constructor!" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "Shubbery creation form default destructor!" << std::endl;
}