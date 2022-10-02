#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Constructor called" << std::endl;
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

bool	PresidentialPardonForm::execute(Bureaucrat const & executor) const
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
			std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
			return (1);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}
}
