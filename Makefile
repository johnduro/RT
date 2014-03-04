# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/04 12:48:29 by mle-roy           #+#    #+#              #
#    Updated: 2014/03/04 12:48:29 by mle-roy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=rt_gh
VERSION=1.0.2
CFLAGS=-Wall -Werror -Wextra -g
INCLUDES=-I ./libft/includes
LIBS=-L ./libft -l ft

SRC=ft_hextoi.c \
	main.c \

OBJ=$(SRC:.c=.o)

all: build $(NAME) finish

build:
	@($(MAKE) -C ./libft)

$(NAME): $(OBJ) ./libft/libft.a
	gcc $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBS)

%.o: %.c rt.h ./libft/includes
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@(rm -rf $(OBJ))

fclean: clean
	@(rm -rf $(NAME))
	@($(MAKE) -C ./libft fclean)

re: fclean all

v:
	@(echo "version: $(VERSION)")

finish:
	@(echo "[\033[32m$(NAME)\033[00m]")

.PHONY: all build clean fclean re v

