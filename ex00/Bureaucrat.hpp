#pragma once
#include <iostream>
#include <exception>

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
		void				subGrad(unsigned int amount);
		//operators
		const Bureaucrat& operator=(const Bureaucrat& other);
	private :
		void				_setGrade(unsigned int grade);
		const std::string	_name;
		unsigned int		_grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);
