WHATEVER	=	whatever

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp

INCLUDES	=	whatever.hpp

all: $(WHATEVER)

$(WHATEVER):	$(SRC) $(INCLUDES)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(WHATEVER)

clean:
	rm -fr $(WHATEVER)

fclean: clean

re: fclean all
