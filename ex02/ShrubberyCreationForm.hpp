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
		virtual std::string getTarget(void) const;
};