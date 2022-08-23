#include "Bureaucrat.hpp"

int main()
{
	std::string  god = "god";
	Bureaucrat a(-1, god);
	Bureaucrat b(160, god);
	Bureaucrat c(1, god);
	std::cout << c << std::endl;
	c.incrementGrade();
}