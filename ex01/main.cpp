#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

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
	std::cout << MAG << "Form testing" << RESET << std::endl;
	try {
		Form testForm = Form("poopoo", 0, 151);
	} catch (std::exception& e) {
		std::cout << YEL << e.what() << RESET << std::endl;
	}
	try {
		Form lolForm = Form("lol", 1, 151);
	} catch (std::exception& e) {
		std::cout << YEL << e.what() << RESET << std::endl;
	}
	try {
		Form blastForm = Form("blast", 0, 150);
	} catch (std::exception& e) {
		std::cout << YEL << e.what() << RESET << std::endl;
	}
	std::cout << MAG << "Bureaucrat testing" << RESET << std::endl;
	Bureaucrat	henry = Bureaucrat("Henry", 45);
	Form		poo = Form("poo", 44, 10);

	henry.signForm(poo);
}

static void valid(void)
{
	std::cout << BLU << "Valid testing" << RESET << std::endl;

	Bureaucrat	john = Bureaucrat("John", 45);
	Form		epic = Form("poo", 45, 10);

	john.signForm(epic);
}

int main(void)
{
	errors();
	valid();
}