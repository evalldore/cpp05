#pragma once
#include <string>
#include "AForm.hpp"

class Intern {
	public:
		enum EForm {
			SHRUBBY,
			PRESIDENTIAL,
			ROBOTY
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
};