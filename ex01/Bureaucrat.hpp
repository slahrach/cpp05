#pragma once
#include <iostream>
#include "./Form.hpp"

class Form;
class Bureaucrat
{
	private :
		std::string _name;
		int	_grade;
	public :
	class GradeTooHighException : public std::exception
	{
		public:
		const char * what() const throw()
		{
			return ("Grade is too high !!");
		}
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char * what() const throw()
		{
			return ("Grade is too low !!");
		}
	};
	Bureaucrat(int grade, std::string& name);
	~Bureaucrat(void);
	Bureaucrat(Bureaucrat &copy);
	Bureaucrat& operator=(Bureaucrat &obj);
	std::string getName(void) const;
	int			getGrade(void) const;
	void		incrementGrade(void);
	void		decrementGrade(void);
	void		signForm(Form& form);
};

std::ostream& operator<<(std::ostream& o, Bureaucrat& obj);