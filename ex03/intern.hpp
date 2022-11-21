#include "Form.hpp"
#include <iostream>

class Intern
{
	std::string name;
	public :
	class ExistException : public std::exception
	{
		public:
		const char * what() const throw();
	};
	Intern(void);
	~Intern(void);
	Intern(Intern& copy);
	Intern& operator = (Intern &obj);
	std::string getName(void) const;
	Form* makeForm(std::string name, std::string target);
};