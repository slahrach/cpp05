#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5), _target("no target")
{
	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Parametrized Constructor called" << std::endl;
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
	return (*this);
}

std::string PresidentialPardonForm::getTarget(void)const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIfSigned() || executor.getGrade() > this->getExecGrade())
	{
		GradeTooLowException e;
		throw e;
	}
	else
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
