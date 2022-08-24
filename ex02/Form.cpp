#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int grade1, int grade2)
{
	try
	{
		if (grade1 < 1 || grade2 < 1)
		{
			Form::GradeTooHighException high;
			throw high;
		}
		else if (grade1 > 150 || grade2 > 150)
		{
			Form::GradeTooLowException low;
			throw low;
		}
		else
		{
			this->sign_grade = grade1;
			this->_name = name;
			this->exec_grade = grade2;
			if_signed = 0;
			std::cout << "Form " << this->_name << " Constructor called" << std::endl;
		}
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

Form::~Form(void)
{
	std::cout << "Form " << this->_name << " Destructor called" << std::endl;
}

Form::Form(void)
{
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(Form& copy)
{
	*this = copy;
	std::cout << "Form " << this->_name << " Copy Constructor called" << std::endl;
}

Form& Form::operator=(Form& obj)
{
	this->_name = obj.getName();
	this->if_signed = obj.getIfSigned();
	this->sign_grade = obj.getSignGrade();
	this->exec_grade = obj.getExecGrade();
	return (*this);
}

bool Form::getIfSigned(void) const
{
	if (this->if_signed)
		return (1);
	else
		return (0);
}

int	Form::getSignGrade(void) const
{
	return (this->sign_grade);
}

int	Form::getExecGrade(void) const
{
	return (this->exec_grade);
}

std::string Form::getName(void) const
{
	return (this->_name);
}

void	Form::beSigned(Bureaucrat& brc)
{
	try
	{
		if (brc.getGrade() > this->sign_grade)
		{
			Form::GradeTooLowException low;
			throw low;
		}
		else if (this->if_signed)
			std::cout << "The form : " << this->getName() << " is already signed" << std::endl;
		else
		{
			this->if_signed = 1;
			std::cout << brc.getName() << " signed form " << this->_name << std::endl;
		}
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Form::setIfSigned(void)
{
	if (!this->if_signed)
		this->if_signed = 1;
}

void	Form::execute(Bureaucrat const & executor) const
{
	try
	{
		if (!this->if_signed || executor.getGrade() > this->exec_grade)
		{
			GradeTooLowException e;
			throw e;
		}
		else
			std::cout << "executor : " << executor.getName() << " can execute " << this->_name << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

std::ostream& operator <<(std::ostream &o, Form& obj)
{
	o << obj.getName() << " Form, has sign grade : " << obj.getSignGrade() << " and execution sign : " << obj.getExecGrade();
	if (obj.getIfSigned())
		o << " . The form is signed" << std::endl;
	else
		o << " . The form is not signed" << std::endl;
	return (o);
}