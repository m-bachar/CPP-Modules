ARRAY		=	Array

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp

INCLUDES	=	Array.hpp

all: $(ARRAY)

$(ARRAY):	$(SRC) $(INCLUDES)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(ARRAY)

clean:
	rm -fr $(ARRAY)

fclean: clean

re: fclean all
