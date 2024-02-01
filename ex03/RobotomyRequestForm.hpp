#pragma once
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		//constructor/destructor
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& form);
		~RobotomyRequestForm(void);
		//method
		bool execute(const Bureaucrat& bureaucrat) const;
		//operators

		const RobotomyRequestForm& operator=(const RobotomyRequestForm& form);
};