#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private :
		std::string	_target;
	public :
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(RobotomyRequestForm& obj);
		virtual std::string getTarget(void) const;
		static int helper;
};