EASYFIND	=	easyfind

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp

INCLUDES	=	easyfind.hpp

all: $(EASYFIND)

$(EASYFIND):	$(SRC) $(INCLUDES)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(EASYFIND)

clean:
	rm -fr $(EASYFIND)

fclean: clean

re: fclean all
