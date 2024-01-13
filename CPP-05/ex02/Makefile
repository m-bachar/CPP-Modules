AFORM		=	AForm

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	Bureaucrat.cpp \
				AForm.cpp \
				main.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp

INCLUDES	=	Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

all: $(AFORM)

$(AFORM): $(SRC) $(INCLUDES)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(AFORM)

clean:
	rm -fr $(AFORM)

fclean: clean

re: fclean all
