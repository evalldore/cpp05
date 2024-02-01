#include <iostream>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm() {}
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy Request", target, 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form) : AForm(form) {}
RobotomyRequestForm::~RobotomyRequestForm(void) {}

bool RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const {
	if (!AForm::execute(bureaucrat)) return false;
	std::cout << "* LOUD DRILLING NOISES * " << std::endl << getTarget();
	srand(time(NULL));
	if (rand() % 2)
		std::cout << " has been successfully robotimized!" << std::endl;
	else
		std::cout << " has failed to be robotimized!" << std::endl;
	return true;
}

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form) {
	if (this == &form) return (*this);
	*this = form;
	return (*this);
}