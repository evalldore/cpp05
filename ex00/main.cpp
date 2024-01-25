#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat henry = Bureaucrat("Henry", 10);

	std::cout << henry << std::endl;
}