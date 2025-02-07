/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:05:09 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/07 12:38:28 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void set_height_width(t_game *so_long, char **map)
{
	int y;

	so_long->map_width = ft_strlen(*map);
	y = 0;
	while (map[y])
		y++;
	so_long->map_height = y;
}

void draw_map(t_game *so_long, char **map, int y, int x)
{
	t_textures textures;
	int i;

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
					textures.exit_closed, x * 64, y * 64);
			i = -1;
			while (++i < so_long->enemy_count)
			{
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
					so_long->texture.velin, so_long->enemy[i].x * 64, so_long->enemy[i].y * 64);
			}
			draw_it(so_long);
		}
	}
}

void set_textures(t_game *so_long)
{
	int height;
	int width;

	// so_long->texture.win = mlx_xpm_file_to_image(so_long->mlx,
	// 		"Bonus/textures/win.xpm", &height, &width);
	// so_long->texture.lose = mlx_xpm_file_to_image(so_long->mlx,
	// 		"Bonus/textures/lose.xpm", &height, &width);
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
	if (!so_long->texture.wall || !so_long->texture.collect || !so_long->texture.exit_closed || !so_long->texture.player || !so_long->texture.space || !so_long->font_img)
	{
		ft_putstr("Error\n");
		dstroy(so_long);
	}
}

void free_textures(t_game *game)
{
	if (game->texture.wall)
		mlx_destroy_image(game->mlx, game->texture.wall);
	if (game->texture.collect)
		mlx_destroy_image(game->mlx, game->texture.collect);
	if (game->texture.exit_closed)
		mlx_destroy_image(game->mlx, game->texture.exit_closed);
	if (game->texture.player)
		mlx_destroy_image(game->mlx, game->texture.player);
	if (game->texture.space)
		mlx_destroy_image(game->mlx, game->texture.space);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
}

int dstroy(t_game *so_long)
{
	free_textures(so_long);
	mlx_destroy_display(so_long->mlx);
	free(so_long->mlx);
	ft_malloc(0, CLEAR);
	exit(1);
	return (1);
}
