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
		AForm(const std::string name, const std::string target, const unsigned int signGrade, const unsigned int execGrade);
		AForm(const AForm& other);
		virtual ~AForm(void) = 0;
		//methods
		virtual bool			execute(const Bureaucrat& bureaucrat) const;
		void					beSigned(const Bureaucrat& bureaucrat);
		bool					isSigned(void) const;
		const std::string		getName() const;
		const std::string		getTarget() const;
		unsigned int			getSignGrade() const;
		unsigned int			getExecGrade() const;
		const AForm&			operator=(const AForm& other);

	private :
		bool					_signed;
		const std::string		_name;
		const std::string		_target;
		const unsigned int		_signGrade;
		const unsigned int		_execGrade;
};

std::ostream& operator<<(std::ostream& out, const AForm& other);