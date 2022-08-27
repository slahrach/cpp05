#include "ShrubberyCreationForm.hpp"
#include <string>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form ("ShrubberyCreationForm", 145, 137), _target(target)
{
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
	return (*this);
}

std::string ShrubberyCreationForm::getTarget(void)const
{
	return (this->_target);
}

bool	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (!this->getIfSigned() || executor.getGrade() > this->getExecGrade())
		{
			GradeTooLowException e;
			throw e;
			return (0);
		}
		else
		{
				std::string	filename;
				filename = this->_target + "_shrubbery";
				std::ofstream fi(filename);
				if (fi.std::ofstream::is_open())
				{
					std::cout << filename << " created !" <<  std::endl;
				fi << "        # #### ####" << std::endl;
				fi <<  "      ### |/#|### |/####" << std::endl;
				fi << "     ##|/#/ |||/##/_/##/_#" << std::endl;
				fi << "   ###  |/###|/ |/ # ###" << std::endl;
				fi << " ##_|_#|_|## | #/###_/_####" << std::endl;
				fi << "## #### # / #| /  #### ##/##" << std::endl;
				fi << " __#_--###`  |{,###---###-~" << std::endl;
				fi << "            |}{" << std::endl;
				fi << "            }}{" << std::endl;
				fi << "            }}{" << std::endl;
				fi << "       	   {{}" << std::endl;
				fi << "      , -=-~{ .-^- _" << std::endl;
				fi << "            `}" << std::endl;
				fi << "             {" << std::endl;
				}
				return (1);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}
}

