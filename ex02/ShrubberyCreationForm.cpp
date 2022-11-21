#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "ShrubberyCreationForm.hpp"
# include <string>
# include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form ("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

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

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (!this->getIfSigned() || executor.getGrade() > this->getExecGrade())
		{
			GradeTooLowException e;
			throw e;
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
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

#endif
