#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	const std::string name = "b1";
	Form f1("name 1", 2, 1);
	std::cout << f1 << std::endl;
	Form f2("name 2", 0, 151);
	Bureaucrat b1(4, name);
	b1.signForm(f1);
	f1.beSigned(b1);
	std::cout << f1.getIfSigned() << std::endl;
}