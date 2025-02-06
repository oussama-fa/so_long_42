# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 20:44:58 by oufarah           #+#    #+#              #
#    Updated: 2025/02/06 08:03:43 by oufarah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_B = so_long_bonus

CC = cc

FLAGS = -Wall -Wextra -Werror 

MLX_FLAGS = -L/home/oufarah/minilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz 

RM = rm -rf

INCS = Mandatory/so_long.h

INCS_B = Bonus/so_long.h

SRC =  Mandatory/get_next_line.c Mandatory/get_next_line_utils.c Mandatory/parsing.c Mandatory/so_long.c \
       Mandatory/parsing_utils.c Mandatory/ft_split.c Mandatory/parsing_map.c Mandatory/parsing_validty.c \
       garbage/garbage.c Mandatory/textures.c Mandatory/moves.c

SRC_B = Bonus/get_next_line.c Bonus/get_next_line_utils.c Bonus/parsing.c Bonus/so_long_bonus.c \
       Bonus/parsing_utils.c Bonus/ft_split.c Bonus/parsing_map.c Bonus/parsing_validty.c \
       garbage/garbage.c Bonus/textures.c Bonus/moves.c

OBJS = $(SRC:.c=.o)

OBJS_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) 

bonus : $(NAME_B)

$(NAME_B): $(OBJS_B)
	$(CC) $(FLAGS) $(OBJS_B) $(MLX_FLAGS) -o $(NAME_B) 

%.o: %.c $(INCS) $(INCS_B)
	$(CC) $(FLAGS) -I/home/oufarah/minilibx-linux -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME) $(NAME_B)

re: fclean all

.PHONY: clean
