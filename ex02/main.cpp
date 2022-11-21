#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	//ShrubberyCreationForm sh("home");
	RobotomyRequestForm r("me");
	RobotomyRequestForm ro1("hey");
	//PresidentialPardonForm p("p");
	const std::string name = "b1";
	Bureaucrat b1(4, name);
	b1.signForm(ro1);
	b1.signForm(r);
	std::cout << ro1.getIfSigned() << std::endl;
	//sh.execute(b1);
	//ro1.execute(b1);
	// ro2.execute(b1);
	b1.executeForm(ro1);
	b1.executeForm(ro1);
}
