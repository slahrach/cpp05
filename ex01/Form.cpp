Form::Form(std::string name, int grade1 int grade2)
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
			std::cout << "Form Constructor called" << std::endl;
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

Form::Form(Form& copy)
{
	*this = copy;
	std::cout << "Form Copy Constructor called" << std::endl;
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

std::ostream& operator <<(std::ostream &o, Form& obj)
{
	o << obj.getName() << "Form, is";
	if (obj.getIfSigned())
		o << "signed" << std::endl;
	else
		o << "not signed" << std::endl;
}