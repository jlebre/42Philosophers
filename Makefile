# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 16:44:48 by marvin            #+#    #+#              #
#    Updated: 2022/10/01 16:44:48 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = @rm -rf
FLAGS = -Wall -Werror -Wextra -pthread -g -fsanitize=thread

NAME = philo

INCLUDE = .

SRC = main.c check.c start_args.c create_philo.c check_if_dead.c print.c \
	destroy_philo.c routine.c colors.c utils.c time.c check_fork.c eat.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	@$(CC) $(OBJ) $(FLAGS) -o $(NAME)
	@echo "██████╗ ██╗  ██╗██╗██╗      ██████╗ "
	@echo "██╔══██╗██║  ██║██║██║     ██╔═══██╗"
	@echo "██████╔╝███████║██║██║     ██║   ██║"
	@echo "██╔═══╝ ██╔══██║██║██║     ██║   ██║"
	@echo "██║     ██║  ██║██║███████╗╚██████╔╝"
	@echo "╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ "
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
