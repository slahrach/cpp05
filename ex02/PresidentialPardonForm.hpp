#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private :
		std::string	_target;
	public :
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(PresidentialPardonForm& obj);
		std::string getTarget(void) const;
		void execute(Bureaucrat const & executor) const;
};