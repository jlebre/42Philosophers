# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 17:09:41 by admin             #+#    #+#              #
#    Updated: 2022/09/16 22:22:07 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = @rm -fr
FLAGS = -Wall -Werror -Wextra -fsanitize=address

NAME = philo

SRC = philo.c

OBJ = $(SRC:.c=.o)

HEADER = philo.h

LIB = .

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) $(FLAGS) -I$(LIB) -o $(NAME)
	@echo "\033[0;32mPush_swap Compiled!\033[0m"

.c.o:
	@$(CC) $(FLAGS) -I$(LIB) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJ)
	@$(MAKE) clean -C
	@echo "\033[0;31m.o Files Removed!\033[0m"

fclean: clean
	$(RM) $(NAME) 
	@$(MAKE) fclean -C
	@echo "\033[0;31mPush_swap Removed!\033[0m"

re: fclean all

.PHONY: all clean fclean re
