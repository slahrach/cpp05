#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private :
		std::string	_target;
	public :
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm& obj);
		std::string getTarget(void) const;
		virtual bool	execute(Bureaucrat const & executor) const;
};