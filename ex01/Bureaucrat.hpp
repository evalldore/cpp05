#pragma once
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
	public :
		//exceptions
		class GradeTooHighException: public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public :
				virtual const char* what() const throw();
		};
		//constructors/destructors
		Bureaucrat(void);
		Bureaucrat(const std::string name, unsigned int grade);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat& other);
		//methods
		const std::string	getName(void) const;
		unsigned int		getGrade(void) const;
		void				addGrade(unsigned int amount);
		void				subGrade(unsigned int amount);
		void				signForm(Form& form);
		//operators
		const Bureaucrat&	operator=(const Bureaucrat& other);
	private :
		void				_setGrade(unsigned int grade);
		const std::string	_name;
		unsigned int		_grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);
