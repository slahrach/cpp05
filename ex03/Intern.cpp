#include "intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) : name("intern")
{
    std::cout << "Intern Constructor called" << std::endl;
}

Intern::~Intern(void)
{
    std::cout << "Intern Destructor Called" << std::endl;
}

Intern::Intern(Intern& copy)
{
    *this = copy;
}

Intern& Intern::operator =(Intern& obj)
{
	this->name = obj.getName();
	return (*this);
}

std::string Intern::getName(void) const
{
	return (this->name);
}

Form* Intern::makeForm(std::string name, std::string target)
{
	std::string names[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 0;
	while (i < 3)
	{
		if (names[i] == name)
			break;
		i++;
	}
	if (i >= 3)
	{
		Intern::ExistException e;
		throw e;
	}
	Form *forms[3];
	forms[0] = new ShrubberyCreationForm(target);
	forms[1] = new RobotomyRequestForm(target);
	forms[2] = new PresidentialPardonForm(target);
	std::cout << i << std::endl;
	int j = 0;
	while (j < 3)
	{
		if (j != i)
			delete forms[j];
		j++;
	}
	return(forms[i]);
}

const char * Intern::ExistException::what() const throw()
{
	return ("Form Name does Not exist");
}