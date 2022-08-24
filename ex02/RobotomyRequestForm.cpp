#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : _target(target)
{
	std::cout << "RobotomyRequestForm Constructor called" << std::endl;
	this->exec_grade = 45;
	this->sign_grade = 72;
	this->_name = "RobotomyRequestForm";
	std::cout << "pwiiiiii....pwiiiii..." << std::endl;
	if (helper %2)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << target << " couldn't be robotomized " << std::endl;
	helper++; 
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
	this->if_signed = obj.getIfSigned();
	this->sign_grade = obj.getSignGrade();
	this->exec_grade = obj.getExecGrade();
	return (*this);
}

std::string RobotomyRequestForm::getTarget(void)const
{
	return (this->_target);
}

int RobotomyRequestForm::helper = 0;