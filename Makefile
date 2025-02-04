# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 20:44:58 by oufarah           #+#    #+#              #
#    Updated: 2025/02/04 04:30:32 by oufarah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
FLAGS = -Wall -Wextra -Werror 
MLX_FLAGS = -L/home/oufarah/minilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz 

RM = rm -rf

INCS = so_long.h

SRC =  get_next_line.c get_next_line_utils.c parsing.c so_long.c \
       parsing_utils.c ft_split.c parsing_map.c parsing_validty.c \
       garbage/garbage.c textures.c moves.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) 

%.o: %.c $(INCS)
	$(CC) $(FLAGS) -I/home/oufarah/minilibx-linux -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
