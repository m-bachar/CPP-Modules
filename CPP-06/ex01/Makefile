SERIALIZER	=	Serialize

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	Serializer.cpp \
				main.cpp

INCLUDES	=	Serializer.hpp

all: $(SERIALIZER)

$(SERIALIZER):	$(SRC) $(INCLUDES)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(SERIALIZER)

clean:
	rm -fr $(SERIALIZER)

fclean: clean

re: fclean all