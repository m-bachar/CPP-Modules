FORM		=	Form

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				Bureaucrat.cpp \
				Form.cpp

INCLUDE1	=	Bureaucrat.hpp

INCLUDE2	=	Form.hpp

all: $(FORM)

$(FORM)	: $(SRC) $(INCLUDE1) $(INCLUDE2)
	$(CPP) $(CPPFLAGS) $(SRC) -o $(FORM)

clean		:
	rm -fr $(FORM)

re			: clean all
