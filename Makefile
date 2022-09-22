# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 17:09:41 by admin             #+#    #+#              #
#    Updated: 2022/09/21 18:39:10 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = @rm -fr
FLAGS = -Wall -Wextra -pthread
#-Werror -fsanitize=address

NAME = philo

INCLUDE = .

SRC = philo.c ft_atoi.c

OBJ = $(SRC:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJ) $(INCLUDE)
	@$(CC) $(OBJ) $(FLAGS) -o $(NAME)
	@echo "\033[0;32mPhilo Compiled!\033[0m"

.c.o:
	@$(CC) $(FLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJ)
	@echo "\033[0;31m.o Files Removed!\033[0m"

fclean: clean
	$(RM) $(NAME) 
	@echo "\033[0;31mPhilo Removed!\033[0m"

re: fclean all

.PHONY: all clean fclean re
