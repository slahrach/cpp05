#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	//ShrubberyCreationForm sh("home");
	//RobotomyRequestForm ro1("me");
	PresidentialPardonForm p("nta");
	const std::string name = "b1";
	Bureaucrat b1(6, name);
	b1.signForm(p);
	std::cout << p.getIfSigned() << std::endl;
	//sh.execute(b1);
	//ro1.execute(b1);
	// ro2.execute(b1);
	b1.executeForm(p);
}
