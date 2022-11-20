#include "Bureaucrat.hpp"

int main()
{
	const std::string lil = "lil";
	Bureaucrat a;
	Bureaucrat b(160, lil);
	Bureaucrat c(1, lil);
	std::cout << c << a << std::endl;
	c.incrementGrade();
	a.decrementGrade();
	c.decrementGrade();
	a.incrementGrade();
	std::cout << c << a<< std::endl;
}