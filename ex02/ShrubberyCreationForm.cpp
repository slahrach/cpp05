#include "ShrubberyCreationForm.hpp"
#include <string>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _target(target)
{
	std::string	filename;
	this->sign_grade = 145;
	this->exec_grade = 137;
	this->if_signed = 1;
	this->_name = "ShrubberyCreationForm";
	filename = this->_target + "_shrubbery";
	std::ofstream fi(filename);
	if (fi.std::ofstream::is_open())
	{
		std::cout << filename << " created !" <<  std::endl;
		fi << "cpp05" << std::endl << "├── ex00" << std::endl <<  "├── ex01" << std::endl << "├── ex02" << std::endl;
		fi <<  "│   ├── Bureaucrat.cpp" << std::endl << "│   ├── Bureaucrat.hpp" << std::endl;
		fi << "│   ├── Form.cpp" << std::endl;
		fi << "│   ├── Makefile" << std::endl;
		fi << "│   ├── Form.hpp" << std::endl;
		fi << "│   ├── main.cpp" << std::endl;
		fi << "│   ├── ShrubberyCreationForm.hpp" << std::endl;
		fi << "│   ├── ShrubberyCreationForm.cpp" << std::endl;
		fi << "│   ├── RobotomyRequestForm.hpp" << std::endl;
		fi << "│   ├── RobotomyRequestForm.cpp" << std::endl;
		fi << "│   ├── PresidentialPardonForm.hpp" << std::endl;
		fi << "│   └── PresidentialPardonForm.cpp" << std::endl;
		fi << "└── ex03" << std::endl;
	}
	// close(fi);
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& copy)
{
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& obj)
{
	this->_target = obj.getTarget();
	this->if_signed = obj.getIfSigned();
	this->sign_grade = obj.getSignGrade();
	this->exec_grade = obj.getExecGrade();
	return (*this);
}

std::string ShrubberyCreationForm::getTarget(void)const
{
	return (this->_target);
}
