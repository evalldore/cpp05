#pragma once
#include <string>
#include <map>
#include <exception>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


class Intern {
	public:
		//enums
		enum EForm {
			SHRUBBY,
			PRESIDENTIAL,
			ROBOTOMY,
			MAX_FORM
		};
		//contructors/destructors
		Intern(void);
		Intern(const Intern&);
		~Intern(void);
		//methods
		AForm* makeForm(const std::string, const std::string);
		//operators
		const Intern& operator=(const Intern&);
	private:
		std::string _formNames[3];
};