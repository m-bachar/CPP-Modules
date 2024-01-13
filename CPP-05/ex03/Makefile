INTERN		=	Intern

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	Bureaucrat.cpp \
				AForm.cpp \
				main.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp \
				Intern.cpp

INCLUDES	=	Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp

all: $(INTERN)

$(INTERN): $(SRC) $(INCLUDES)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(INTERN)

clean:
	rm -fr $(INTERN)

fclean: clean

re: fclean all
