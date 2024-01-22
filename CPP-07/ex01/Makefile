ITER		=	iter

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp

INCLUDES	=	iter.hpp

all: $(ITER)

$(ITER):	$(SRC) $(INCLUDES)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(ITER)

clean:
	rm -fr $(ITER)

fclean: clean

re: fclean all
