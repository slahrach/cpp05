NAME = forms

STDFLAGS = -std=c++98

FLAGS = -Wall -Wextra -Werror

all :
	clang++ main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp ${FLAGS} ${STDFLAGS} -o ${NAME}

clean :
	rm -rf ${NAME}

fclean : clean

re : clean all