# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoxe <amoxe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 18:21:48 by amoxe             #+#    #+#              #
#    Updated: 2021/10/08 17:30:33 by amoxe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
SRC = main.c split.c ft_substr.c
ObJ = ${SRC:.c=.o}
FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}:
	@$(CC) $(SRC) $(FLAGS) -o ${NAME}
			
clean:
	rm -rf $(ObJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all