#include <iostream>
#include <cstdlib>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm() {}
PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidential Pardon", target, 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form) : AForm(form) {}
PresidentialPardonForm::~PresidentialPardonForm(void) {}

bool PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const {
	if (!AForm::execute(bureaucrat)) return false;
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return true;
}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& form) {
	if (this == &form) return (*this);
	*this = form;
	return (*this);
}