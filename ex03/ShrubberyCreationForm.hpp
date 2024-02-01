#pragma once
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		//constructor/destructor
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& form);
		~ShrubberyCreationForm(void);
		//method
		bool execute(const Bureaucrat& bureaucrat) const;
		//operators

		const ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);
};