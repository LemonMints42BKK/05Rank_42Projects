# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 13:07:47 by pnopjira          #+#    #+#              #
#    Updated: 2023/12/27 20:30:17 by pnopjira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex01
SRC			= main.cpp Bureaucrat.cpp Form.cpp
OBJ			= $(SRC:.cpp=.o)
HDR			= Bureaucrat.hpp Form.hpp
CC			= c++
RM 			= rm -rf
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re