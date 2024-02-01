#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

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
	ShrubberyCreationForm Shrub = ShrubberyCreationForm("home");

	henry.signForm(Shrub);
	henry.executeForm(Shrub);
}

static void valid(void) {
	std::cout << BLU << "Valid testing" << RESET << std::endl;

	Bureaucrat henry = Bureaucrat("Henry", 120);
	ShrubberyCreationForm Shrub = ShrubberyCreationForm("home");
	PresidentialPardonForm Presidential = PresidentialPardonForm("me");

	henry.signForm(Shrub);
	henry.executeForm(Shrub);
	henry.signForm(Presidential);
	henry.executeForm(Presidential);
}

int main(void) {
	errors();
	valid();
}