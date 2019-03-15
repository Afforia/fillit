# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thaley <thaley@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/06 18:57:03 by thaley            #+#    #+#              #
#    Updated: 2019/03/15 19:02:26 by thaley           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

INCLUDES = libft/libft.h fillit.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		make -C libft/
		$(CC) $(CFLAGS) -c $(SRC) -I $(INCLUDES)
		$(CC) $(FLAGS) $(OBJ) -L libft/ -lft -o $(NAME)

clean:
		/bin/rm -f $(OBJ) $(wildcard *.gch)
		make clean -C libft/

fclean: clean
		/bin/rm -f $(NAME)
		make fclean -C libft/

re: fclean all
