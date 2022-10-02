#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form ("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& copy)
{
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& obj)
{
	this->_target = obj.getTarget();
	return (*this);
}

std::string RobotomyRequestForm::getTarget(void)const
{
	return (this->_target);
}

bool	RobotomyRequestForm::execute(Bureaucrat const & executor) const
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
				std::cout << "pwiiiiii....pwiiiii..." << std::endl;
				if (helper %2)
					std::cout << this->_target << " has been robotomized successfully" << std::endl;
				else
					std::cout << this->_target << " couldn't be robotomized " << std::endl;
				helper++; 
				return (1);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}
}

int RobotomyRequestForm::helper = 0;