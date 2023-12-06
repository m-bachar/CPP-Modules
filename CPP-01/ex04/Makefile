REPLACE		=	Replace

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp

all: $(REPLACE)

$(REPLACE)	:
	$(CPP) $(CPPFLAGS) $(SRC) -o $(REPLACE)

clean		:
	rm -fr $(REPLACE)

re			: clean all
	rm -fr *.replace
