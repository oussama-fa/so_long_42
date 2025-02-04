/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:05:09 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/04 06:11:09 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_height_width(t_game *so_long, char **map)
{
	int	y;

	so_long->map_width = ft_strlen(*map);
	y = 0;
	while (map[y])
		y++;
	so_long->map_height = y;
}

void	draw_map(t_game *so_long, char **map, int y, int x)
{
	t_textures	textures;

	textures = so_long->texture;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
				textures.space, x * 64, y * 64);
			if (map[y][x] == '1')
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
					textures.wall, x * 64, y * 64);
			if (map[y][x] == 'P')
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
					textures.player, x * 64, y * 64);
			if (map[y][x] == 'C')
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
					textures.collect, x * 64, y * 64);
			if (map[y][x] == 'E')
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
					textures.exit, x * 64, y * 64);
		}
	}
}

void	set_textures(t_game *so_long)
{
	int	height;
	int	width;

	so_long->texture.wall = mlx_xpm_file_to_image(so_long->mlx,
			"textures/wall.xpm", &height, &width);
	so_long->texture.collect = mlx_xpm_file_to_image(so_long->mlx,
			"textures/collect.xpm", &height, &width);
	so_long->texture.exit = mlx_xpm_file_to_image(so_long->mlx,
			"textures/exit.xpm", &height, &width);
	so_long->texture.player = mlx_xpm_file_to_image(so_long->mlx,
			"textures/player.xpm", &height, &width);
	so_long->texture.space = mlx_xpm_file_to_image(so_long->mlx,
			"textures/background.xpm", &height, &width);
	if (!so_long->texture.wall || !so_long->texture.collect
		|| !so_long->texture.exit || !so_long->texture.player
		|| !so_long->texture.space)
	{
		print_err("Closed!\n");
		dstroy(so_long);
	}
}

int	dstroy(t_game *so_long)
{
	mlx_clear_window(so_long->mlx, so_long->mlx_win);
	mlx_destroy_window(so_long->mlx, so_long->mlx_win);
	exit(1);
	return (1);
}
