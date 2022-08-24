#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : _target(target)
{
	std::cout << "PresidentialPardonForm Constructor called" << std::endl;
	this->exec_grade = 5;
	this->sign_grade = 25;
	this->_name = "PresidentialPardonForm";
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& copy)
{
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& obj)
{
	this->_target = obj.getTarget();
	this->if_signed = obj.getIfSigned();
	this->sign_grade = obj.getSignGrade();
	this->exec_grade = obj.getExecGrade();
	return (*this);
}

std::string PresidentialPardonForm::getTarget(void)const
{
	return (this->_target);
}
