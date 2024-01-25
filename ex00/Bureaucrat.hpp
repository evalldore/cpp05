#pragma once
#include <iostream>

class Bureaucrat {
	public :
		Bureaucrat(void);
		Bureaucrat(const std::string name, uint32_t grade);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat& other);

		const std::string	getName(void) const;
		uint32_t			getGrade(void) const;

		const Bureaucrat& operator=(const Bureaucrat& other);
	private :
		const std::string	_name;
		uint32_t			_grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);
