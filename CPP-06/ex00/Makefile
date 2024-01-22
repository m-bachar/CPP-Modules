CONVERT		=	convert

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	ScalarConverter.cpp \
				main.cpp

INCLUDES	=	ScalarConverter.hpp

all: $(CONVERT)

$(CONVERT):	$(SRC) $(INCLUDES)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(CONVERT)

clean:
	rm -fr $(CONVERT)

fclean: clean

re: fclean all