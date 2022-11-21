#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form ("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form ("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Parametrized Constructor called" << std::endl;
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

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIfSigned() || executor.getGrade() > this->getExecGrade())
	{
		GradeTooLowException e;
		throw e;
	}
	else
	{
		std::cout << "zzzz....zzzzz..." << std::endl;
		if (helper %2)
			std::cout << this->_target << " has been robotomized successfully" << std::endl;
		else
			std::cout << this->_target << " couldn't be robotomized " << std::endl;
		helper++;
	}
}

int RobotomyRequestForm::helper = 0;