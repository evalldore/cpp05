#pragma once
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
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
		Form(void);
		Form(const std::string name, const unsigned int signGrade, const unsigned int execGrade);
		Form(const Form& other);
		~Form(void);
		//methods
		void					beSigned(const Bureaucrat& bureaucrat);
		bool					isSigned(void) const;
		const std::string		getName() const;
		unsigned int			getSignGrade() const;
		unsigned int			getExecGrade() const;
		const Form&				operator=(const Form& other);

	private :
		bool				_signed;
		const std::string	_name;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;
};

std::ostream& operator<<(std::ostream& out, const Form& other);