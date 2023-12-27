BUREAUCRAT	=	Bureaucrat

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				Bureaucrat.cpp

INCLUDE		=	Bureaucrat.hpp

all: $(BUREAUCRAT)

$(BUREAUCRAT)	: $(SRC) $(INCLUDE)
	$(CPP) $(CPPFLAGS) $(SRC) -o $(BUREAUCRAT)

clean		:
	rm -fr $(BUREAUCRAT)

re			: clean all
