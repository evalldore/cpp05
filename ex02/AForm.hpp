#pragma once
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public :
		//exceptions
		class GradeTooHighException: public std::exception {
			public :
				virtual const char* what(void) const throw();
		};
		class GradeTooLowException: public std::exception {
			public :
				virtual const char* what(void) const throw();
		};
		class SignedException: public std::exception {
			public :
				virtual const char* what(void) const throw();
		};
		//constructors/destructors
		AForm(void);
		AForm(const std::string name, const unsigned int signGrade, const unsigned int execGrade);
		AForm(const AForm& other);
		~AForm(void);
		//methods
		void					execute(const Bureaucrat& bureaucrat) const;
		void					beSigned(const Bureaucrat& bureaucrat);
		bool					isSigned(void) const;
		const std::string		getName() const;
		unsigned int			getSignGrade() const;
		unsigned int			getExecGrade() const;
		const AForm&			operator=(const AForm& other);

	private :
		bool				_signed;
		const std::string	_name;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;
};

std::ostream& operator<<(std::ostream& out, const AForm& other);