#pragma once
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		//constructor/destructor
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& form);
		~PresidentialPardonForm(void);
		//method
		bool execute(const Bureaucrat& bureaucrat) const;
		//operators

		const PresidentialPardonForm& operator=(const PresidentialPardonForm& form);
};