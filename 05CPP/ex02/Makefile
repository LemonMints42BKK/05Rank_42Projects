# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 13:07:47 by pnopjira          #+#    #+#              #
#    Updated: 2023/12/21 13:22:58 by pnopjira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex02
SRC			= main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp 
OBJ			= $(SRC:.cpp=.o)
CC			= c++
RM 			= rm -rf
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) *shrubbery
 
fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re