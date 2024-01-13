FORM		=	Form

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	Bureaucrat.cpp \
				Form.cpp \
				main.cpp

INCLUDES	=	Bureaucrat.hpp Form.hpp

all: $(FORM)

$(FORM): $(SRC) $(INCLUDES)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(FORM)

clean:
	rm -fr $(FORM)

fclean: clean

re: fclean all