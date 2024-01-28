SPAN		=	Span

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				Span.cpp

INCLUDES	=	Span.hpp

all: $(SPAN)

$(SPAN):	$(SRC) $(INCLUDES)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(SPAN)

clean:
	rm -fr $(SPAN)

fclean: clean

re: fclean all
