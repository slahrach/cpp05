#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade, std::string& name)
{
	try
	{
		if (grade < 1)
		{
			Bureaucrat::GradeTooHighException high;
			throw high;
		}
		else if (grade > 150)
		{
			Bureaucrat::GradeTooLowException low;
			throw low;
		}
		else
		{
			this->_grade = grade;
			this->_name = name;
			std::cout << "Constructor called" << std::endl;
		}
	}
	catch(const Bureaucrat::GradeTooHighException& high_e)
	{
		std::cerr << high_e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& low_e)
	{
		std::cerr << low_e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat& copy)
{
	*this = copy;
	std::cout << "Copy Constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& obj)
{
	this->_grade = obj.getGrade();
	this->_name = obj.getName();
	return (*this);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

void	Bureaucrat::incrementGrade(void)
{
	try
	{
		if (this->_grade == 1)
		{
			Bureaucrat::GradeTooHighException high;
			throw high;
		}
		else
			(this->_grade)--;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		if (this->_grade == 150)
		{
			Bureaucrat::GradeTooLowException high;
			throw high;
		}
		else
			(this->_grade)++;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

void	Bureaucrat::signForm(Form& form)
{
	if (form.getIfSigned())
		std::cout << "The form : " << form.getName() << " is already signed" << std::endl;
	else if(this->_grade <= form.getSignGrade())
	{
		form.setIfSigned();
		std::cout << this->_name << " signed form : " << form.getName() << std::endl;
	}
	else
		std::cout << this->_name << " couldn't sign form : " << form.getName() << ", because his grade is lower than required" << std::endl;
}

std::ostream& operator<<(std::ostream& o, Bureaucrat& obj)
{
	o << obj.getName() << ", Bureaucrat " << obj.getGrade() << std::endl;
	return (o);
}
