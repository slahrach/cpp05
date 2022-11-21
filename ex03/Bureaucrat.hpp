#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Form;
class Bureaucrat
{
	private :
		const std::string _name;
		int	_grade;
	public :
	class GradeTooHighException : public std::exception
	{
		public:
		const char * what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char * what() const throw();
	};
	Bureaucrat(void);
	Bureaucrat(int grade, const std::string& name);
	~Bureaucrat(void);
	Bureaucrat(Bureaucrat &copy);
	Bureaucrat& operator=(Bureaucrat &obj);
	std::string getName(void) const;
	int			getGrade(void) const;
	void		incrementGrade(void);
	void		decrementGrade(void);
	void		signForm(Form& form);
	void 		executeForm(Form const & form);

};

std::ostream& operator<<(std::ostream& o, Bureaucrat& obj);
#endif