# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thaley <thaley@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/10 15:34:58 by thaley            #+#    #+#              #
#    Updated: 2019/02/24 18:48:26 by thaley           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

INCLUDES = libft/libft.h fillit.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -g #dont forget remove -g

#SRC = main.c crt_del.c solution.c check.c read_and_record.c
SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		make -C libft/
		$(CC) $(CFLAGS) -c $(SRC) -I $(INCLUDES)
		$(CC) $(FLAGS) $(OBJ) -L libft/ -lft -o $(NAME)

clean:
		/bin/rm -f $(OBJ) *.gch
		make clean -C libft/

fclean: clean
		/bin/rm -f $(NAME)
		make fclean -C libft/

re: fclean all
