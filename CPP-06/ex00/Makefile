SCALARCONVERTER	=	ScalarConverter

CC				=	cc

CPPFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC				=	ScalarConverter.cpp \
					main.cpp

INCLUDES		=	ScalarConverter.hpp


all: $(SCALARCONVERTER)

$(SCALARCONVERTER): $(SRC) $(INCLUDES)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(SCALARCONVERTER)

clean:
	rm -fr $(SCALARCONVERTER)

fclean: clean

re: fclean all
