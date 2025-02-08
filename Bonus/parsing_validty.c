/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_validty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:28:24 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/08 22:22:49 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = '1';
		return ;
	}
	map[y][x] = '1';
	flood_fill(map, y - 1, x);
	flood_fill(map, y + 1, x);
	flood_fill(map, y, x - 1);
	flood_fill(map, y, x + 1);
}

void	check_valid_path(char **map_cpy, int y, int x)
{
	int	tmpx;

	while (map_cpy[y])
	{
		tmpx = x;
		while (map_cpy[y][tmpx])
		{
			if (map_cpy[y][tmpx] == 'C' || map_cpy[y][tmpx] == 'E')
				return (print_err("Invalide Map\n"));
			tmpx++;
		}
		y++;
	}	
}

t_pos	get_player_pos(char **map)
{
	t_pos	cor;

	cor.y = 0;
	while (map[cor.y])
	{
		cor.x = 0;
		while (map[cor.y][cor.x])
		{
			if (map[cor.y][cor.x] == 'P')
				return (cor);
			cor.x++;
		}
		cor.y++;
	}
	return (cor);
}

void	set_height_width(t_game *so_long, char **map)
{
	int	y;

	so_long->map_width = ft_strlen(*map);
	y = 0;
	while (map[y])
		y++;
	so_long->map_height = y;
}
