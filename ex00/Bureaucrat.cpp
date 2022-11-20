#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Bureaucrat"), _grade(150)
{
	std::cout << "Default Constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(int grade, const std::string& name) : _name(name), _grade(grade)
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
			std::cout << "Parameterized Constructor called" << std::endl;
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

Bureaucrat::Bureaucrat(Bureaucrat& copy) : _name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << "Copy Constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& obj)
{
	this->_grade = obj.getGrade();
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

std::ostream& operator<<(std::ostream& o, Bureaucrat& obj)
{
	o << obj.getName() << ", Bureaucrat " << obj.getGrade() << std::endl;
	return (o);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return("grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return("grade too low");
}