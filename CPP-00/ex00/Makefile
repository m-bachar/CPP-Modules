# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 20:05:03 by mbachar           #+#    #+#              #
#    Updated: 2023/09/15 20:28:07 by mbachar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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