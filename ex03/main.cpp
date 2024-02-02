#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

#define RESET "\e[0m"

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

static void errors (void) {
	std::cout << RED << "Errors testing" << RESET << std::endl;

	Bureaucrat henry = Bureaucrat("Henry", 150);
	Intern inter = Intern();
	AForm* pooForm = inter.makeForm("poo pardon", "me");
	if (!pooForm)
		std::cout << "no poo" << std::endl;
}

static void valid(void) {
	std::cout << BLU << "Valid testing" << RESET << std::endl;
	Bureaucrat henry = Bureaucrat("Henry", 1);
	Intern inter = Intern();
	std::cout << GRN << "Presidential Pardon" << RESET << std::endl;
	AForm* presForm = inter.makeForm("presidential pardon", "me");
	if (presForm)
	{
		henry.signForm(*presForm);
		henry.executeForm(*presForm);
		delete presForm;
	}
	std::cout << GRN << "Shrubbery creation" << RESET << std::endl;
	AForm* shrub = inter.makeForm("shrubbery creation", "me");
	if (shrub)
	{
		henry.signForm(*shrub);
		henry.executeForm(*shrub);
		delete shrub;
	}
	std::cout << GRN << "Robotomy request" << RESET << std::endl;
	AForm* robot = inter.makeForm("robotomy request", "me");
	if (robot)
	{
		henry.signForm(*robot);
		henry.executeForm(*robot);
		delete robot;
	}
}

int main(void) {
	errors();
	valid();
}