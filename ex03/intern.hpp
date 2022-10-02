#include "Form.hpp"
#include <iostream>

class Intern
{
    Intern(void);
    ~Intern(void);
    Intern(Intern& copy);
    Intern& operator = (Intern &obj);
    Form* makeForm(std::string name, std::string target);
};