RPN			=	RPN

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				RPN.cpp

INCLUDES	=	RPN.hpp

all: $(RPN)

$(RPN):	$(SRC) $(INCLUDES)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(RPN)

clean:
	rm -fr $(RPN)

fclean: clean

re: fclean all
