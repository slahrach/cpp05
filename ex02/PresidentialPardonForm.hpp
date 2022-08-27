#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private :
		std::string	_target;
	public :
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(PresidentialPardonForm& obj);
		std::string getTarget(void) const;
		virtual bool	execute(Bureaucrat const & executor) const;
};