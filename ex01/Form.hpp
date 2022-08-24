#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private :
	std::string _name;
	bool	if_signed;
	int		sign_grade;
	int		exec_grade;
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
	Form(std::string name, int grade1, int grade2);
	~Form(void);
	Form(Form& copy);
	Form& operator=(Form& obj);
	std::string getName(void) const;
	bool	getIfSigned(void)const;
	void	setIfSigned(void);
	int		getSignGrade(void) const;
	int		getExecGrade(void) const;
	void	beSigned(Bureaucrat& brc);
};

std::ostream& operator <<(std::ostream &o, Form& obj);