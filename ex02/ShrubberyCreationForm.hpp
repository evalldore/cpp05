#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:

	ShrubberyCreationForm(void);
	~ShrubberyCreationForm(void);
	bool execute(const Bureaucrat& bureaucrat) const;
};