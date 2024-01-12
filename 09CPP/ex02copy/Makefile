# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 13:07:47 by pnopjira          #+#    #+#              #
#    Updated: 2024/01/11 10:58:23 by pnopjira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= PmergeMe
SRC			= main.cpp PmergeMe.cpp
OBJ			= $(SRC:.cpp=.o)
HED			= PmergeMe.hpp
CC			= c++
RM 			= rm -rf
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJ) $(HED)
	$(CC) $(CPPFLAGS) -c -o main.o main.cpp
	$(CC) $(CPPFLAGS) -c -o PmergeMe.o PmergeMe.cpp
	$(CC) $(CPPFLAGS) -o $(NAME) PmergeMe.o main.o

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re