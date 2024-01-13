BUREAUCRAT	=	Bureaucrat

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	Bureaucrat.cpp \
				main.cpp

INCLUDES	=	Bureaucrat.hpp

all: $(BUREAUCRAT)

$(BUREAUCRAT):	$(SRC) $(INCLUDES)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(BUREAUCRAT)

clean:
	rm -fr $(BUREAUCRAT)

fclean: clean

re: fclean all