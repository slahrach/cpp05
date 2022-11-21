#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private :
		std::string	_target;
	public :
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(RobotomyRequestForm& obj);
		virtual std::string getTarget(void) const;
		void execute(Bureaucrat const & executor) const;
		static int helper;
};