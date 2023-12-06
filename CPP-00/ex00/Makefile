MEGAPHONE	=	megaphone

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	megaphone.cpp

all: $(MEGAPHONE)

$(MEGAPHONE) :
	$(CPP) $(CPPFLAGS) $(SRC) -o $(MEGAPHONE)

clean		:
	rm -fr $(MEGAPHONE)

re			: clean all
