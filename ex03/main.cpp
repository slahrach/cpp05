#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "intern.hpp"

int main()
{
	try
	{
		const std::string name = "b1";
		Bureaucrat b1(4, name);
		Intern i;
		Form *f;
		f = i.makeForm("RootomyRequestForm", "target");
		b1.signForm(*f);
		f->execute(b1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	while (1);
}