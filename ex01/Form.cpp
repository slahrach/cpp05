#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("form"), if_signed(0), sign_grade(150), exec_grade(150)
{
	std::cout << "Form Default Constructor Called" << std::endl;
}

Form::Form(std::string name, int grade1, int grade2) : _name(name), if_signed(0), sign_grade(grade1), exec_grade(grade2)
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
			std::cout << "Form Parametrized Constructor called" << std::endl;
		}
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

Form::~Form(void)
{
	std::cout << "Form Destructor called" << std::endl;
}

Form::Form(Form& copy) : _name(copy.getName()), if_signed(copy.getIfSigned()), sign_grade(copy.getSignGrade()), exec_grade(copy.getExecGrade())
{
	std::cout << "Form Copy Constructor called" << std::endl;
}

Form& Form::operator=(Form& obj)
{
	this->if_signed = obj.getIfSigned();
	return (*this);
}

bool Form::getIfSigned(void) const
{
	return (this->if_signed);
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
		else
			this->if_signed = 1;
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

std::ostream& operator <<(std::ostream &o, Form& obj)
{
	o << obj.getName() << " Form, has sign grade : " << obj.getSignGrade() << " and execution grade : " << obj.getExecGrade();
	if (obj.getIfSigned())
		o << " , The form is signed" << std::endl;
	else
		o << " , The form is not signed" << std::endl;
	return (o);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return("grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return("grade too low");
}