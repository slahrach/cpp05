#include "intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
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
    return (*this);
}

Form* makeForm(std::string name, std::string target)
{
    std::string names[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
    Form forms[3] = {new Robo}
}