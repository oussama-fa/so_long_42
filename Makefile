# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 20:44:58 by oufarah           #+#    #+#              #
#    Updated: 2025/02/01 05:15:35 by oufarah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

INCS = so_long.h

SRC =  get_next_line.c  get_next_line_utils.c  parsing.c  so_long.c parsing_utils.c ft_split.c parsing_map.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME) :$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(INCS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : clean