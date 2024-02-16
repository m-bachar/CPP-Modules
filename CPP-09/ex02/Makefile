PMM			=	PmergeMe

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				PmergeMe.cpp

INCLUDES	=	PmergeMe.hpp

all: $(PMM)

$(PMM):	$(SRC) $(INCLUDES)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(PMM)

clean:
	rm -fr $(PMM)

fclean: clean

re: fclean all
