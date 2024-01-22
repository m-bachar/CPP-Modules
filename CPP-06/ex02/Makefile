Identify	=	Identify

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	Base.cpp \
				A.cpp \
				B.cpp \
				C.cpp \
				utils.cpp \
				main.cpp

INCLUDES	=	Base.hpp A.hpp b.hpp C.hpp utils.hpp

all: $(Identify)

$(Identify):	$(SRC) $(INCLUDES)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(Identify)

clean:
	rm -fr $(Identify)

fclean: clean

re: fclean all
