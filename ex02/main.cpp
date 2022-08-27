#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	ShrubberyCreationForm sh("home");
	RobotomyRequestForm ro1("ana");
	PresidentialPardonForm ro2("nta");
	std::string name = "b1";
	Bureaucrat b1(5, name);
	sh.execute(b1);
	ro1.execute(b1);
	ro2.execute(b1);
	b1.executeForm(ro2);
}
