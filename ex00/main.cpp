#include <iostream>
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
	{
		try {
			Bureaucrat henry = Bureaucrat("Henry", 0);

			std::cout << henry << std::endl;
		} catch (std::exception& e) {
			std::cout << YEL << "Creating bureaucrat error " << e.what() << RESET << std::endl;
		}
	}
	{
		try {
			Bureaucrat john = Bureaucrat("Johny", 151);

			std::cout << john << std::endl;
		} catch (std::exception& e) {
			std::cout << YEL << "Creating bureaucrat error " << e.what() << RESET << std::endl;
		}
	}
	{
		Bureaucrat Piss = Bureaucrat("Piss", 3);
		try {
			Piss.addGrade(3);
			std::cout << Piss << std::endl;
		} catch (std::exception& e) {
			std::cout << YEL << "Incrementing bureaucrat grade error " << e.what() << RESET << std::endl;
		}
	}
	{
		Bureaucrat Cool = Bureaucrat("Cool", 149);
		try {
			Cool.subGrade(3);
			std::cout << Cool << std::endl;
		} catch (std::exception& e) {
			std::cout << YEL << "Decrementing bureaucrat grade error " << e.what() << RESET << std::endl;
		}
	}
}

static void valid(void)
{
	std::cout << BLU << "Valid testing" << RESET << std::endl;

	{
		Bureaucrat Epic = Bureaucrat("Epic", 1);
		try {
			Epic.subGrade(1);
			std::cout << Epic << std::endl;
			Epic.subGrade(10);
			std::cout << Epic << std::endl;
		} catch (std::exception& e) {
			std::cout << YEL << "Decrementing bureaucrat grade error " << e.what() << RESET << std::endl;
		}
	}
	{
		Bureaucrat Cool = Bureaucrat("Cool", 149);
		try {
			Cool.addGrade(1);
			std::cout << Cool << std::endl;
			Cool.addGrade(10);
			std::cout << Cool << std::endl;
		} catch (std::exception& e) {
			std::cout << YEL << "Incrementing bureaucrat grade error " << e.what() << RESET << std::endl;
		}
	}
}

int main(void)
{
	errors();
	valid();
}