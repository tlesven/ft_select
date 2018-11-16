# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/08 15:07:05 by tlesven           #+#    #+#              #
#    Updated: 2014/01/11 14:56:50 by tlesven          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c -I ~/libft/includes -c
TERMFLAGS = -L /usr/lib -ltermcap
LDFLAGS = -L ~/libft -lft
RM = rm -rf

NAME = ft_select
SRC = main.c \
	  ft_select.c \
	  list.c \
	  ft_cmd.c \
	  ft_signal.c \

OBJ=$(subst .c,.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(LDFLAGS) $(TERMFLAGS) $^

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
