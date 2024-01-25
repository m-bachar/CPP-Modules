MUTANTSTACK	=	MutantStack

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp

INCLUDES	=	MutantStack.hpp

all: $(MUTANTSTACK)

$(MUTANTSTACK):	$(SRC) $(INCLUDES)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(MUTANTSTACK)

clean:
	rm -fr $(MUTANTSTACK)

fclean: clean

re: fclean all
