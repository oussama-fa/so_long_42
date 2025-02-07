/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:05:09 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/07 14:09:06 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(t_game *so_long, char **map, int y, int x)
{
	t_textures	textures;

	textures = so_long->texture;
	if (map[y][x] == '1')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			textures.wall, x * 64, y * 64);
	if (map[y][x] == 'P')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			textures.player, x * 64, y * 64);
	if (map[y][x] == 'C')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			textures.collect, x * 64, y * 64);
	if (map[y][x] == 'E' && so_long->coin != 0)
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			textures.exit_closed, x * 64, y * 64);
	if (map[y][x] == 'E' && so_long->coin == 0)
		collect_all_coll(so_long);
}

void	draw_map(t_game *so_long, char **map, int y, int x)
{
	t_textures	textures;
	int			i;

	textures = so_long->texture;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
				textures.space, x * 64, y * 64);
			draw(so_long, so_long->map, y, x);
			i = -1;
			while (++i < so_long->enemy_count)
			{
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
					so_long->texture.velin, so_long->enemy[i].x * 64,
					so_long->enemy[i].y * 64);
			}
		}
	}
}

void	collect_all_coll(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->texture.exit, x * 64, y * 64);
		}
	}
}

void	set_player_texter(t_game *so_long)
{
	int	height;
	int	width;

	so_long->texture.player_down = mlx_xpm_file_to_image(so_long->mlx,
			"Bonus/textures/player_down.xpm", &height, &width);
	so_long->texture.player_left = mlx_xpm_file_to_image(so_long->mlx,
			"Bonus/textures/player_left.xpm", &height, &width);
	so_long->texture.player_right = mlx_xpm_file_to_image(so_long->mlx,
			"Bonus/textures/player_right.xpm", &height, &width);
	so_long->texture.player_up = mlx_xpm_file_to_image(so_long->mlx,
			"Bonus/textures/player_up.xpm", &height, &width);
	if (!so_long->texture.player_left || !so_long->texture.player_right
		|| !so_long->texture.player_down || !so_long->texture.player_up)
	{
		ft_putstr("Error in Textures\n");
		dstroy(so_long);
	}
}

void	set_textures(t_game *so_long)
{
	int	height;
	int	width;

	set_player_texter(so_long);
	so_long->texture.exit = mlx_xpm_file_to_image(so_long->mlx,
			"Bonus/textures/exit.xpm", &height, &width);
	so_long->texture.velin = mlx_xpm_file_to_image(so_long->mlx,
			"Bonus/textures/enemy_down.xpm", &height, &width);
	so_long->texture.wall = mlx_xpm_file_to_image(so_long->mlx,
			"Bonus/textures/wall.xpm", &height, &width);
	so_long->texture.collect = mlx_xpm_file_to_image(so_long->mlx,
			"Bonus/textures/collect.xpm", &height, &width);
	so_long->texture.exit_closed = mlx_xpm_file_to_image(so_long->mlx,
			"Bonus/textures/exit_closed.xpm", &height, &width);
	so_long->texture.player = mlx_xpm_file_to_image(so_long->mlx,
			"Bonus/textures/player.xpm", &height, &width);
	so_long->texture.space = mlx_xpm_file_to_image(so_long->mlx,
			"Bonus/textures/background.xpm", &height, &width);
	if (!so_long->texture.wall || !so_long->texture.collect
		|| !so_long->texture.exit_closed || !so_long->texture.player
		|| !so_long->texture.space || !so_long->texture.velin)
	{
		ft_putstr("Error in Textures\n");
		dstroy(so_long);
	}
}
