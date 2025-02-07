/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 04:30:15 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/07 20:53:43 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_position(t_game *game)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = -1;
	game->enemy = ft_malloc(sizeof(t_pos) * game->enemy_count, ALLOC);
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			if (game->map[y][x] == 'V')
			{
				game->enemy[i].x = x;
				game->enemy[i].y = y;
				i++;
			}
		}
	}
}

void	enemy(t_game *game, int new_y, int new_x, int i)
{
	if (new_x >= 0 && new_x < game->map_width && new_y >= 0
		&& new_y < game->map_height && (game->map[new_y][new_x] != '1'
		&& game->map[new_y][new_x] != 'C' && game->map[new_y][new_x] != 'V'
		&& game->map[new_y][new_x] != 'E'))
	{
		if (game->map[new_y][new_x] == 'P')
			(ft_putstr("You Lose\n"), dstroy(game));
		game->map[game->enemy[i].y][game->enemy[i].x] = '0';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->texture.space, game->enemy[i].x, game->enemy[i].y);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->texture.velin, new_x, new_y);
		game->enemy[i].x = new_x;
		game->enemy[i].y = new_y;
		game->map[game->enemy[i].y][game->enemy[i].x] = 'V';
	}
}

void	move_enemy(t_game *game)
{
	int	i;
	int	new_x;
	int	new_y;
	int	dir;

	i = -1;
	while (++i < game->enemy_count)
	{
		new_x = game->enemy[i].x;
		new_y = game->enemy[i].y;
		dir = rand() % 4;
		if (dir == 0)
			new_x--;
		else if (dir == 1)
			new_x++;
		else if (dir == 2)
			new_y--;
		else if (dir == 3)
			new_y++;
		enemy(game, new_y, new_x, i);
	}
}
