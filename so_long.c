/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:48:54 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/04 00:51:41 by oufarah          ###   ########.fr       */
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

void	draw_map(t_game *so_long, char **map)
{
	t_textures	textures;
	int			y;
	int			x;

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
}

int	dstroy(t_game *so_long)
{
	printf("%s",*so_long->map);
	//destroy
	exit(1);
}

int	key_hook(int keycode, t_game *param)
{
	t_pos	*player;
	char	**map;

	player = &param->player;
	map = param->map;
	if (keycode == 119)
	{
		if (map[player->y - 1][player->x] != '1')
		{
			map[player->y][player->x] = '0';
			map[player->y - 1][player->x] = 'P';
			player->y--;
		}
	}
	else if (keycode == 115)
	{
		if (map[player->y + 1][player->x] != '1')
		{
			map[player->y][player->x] = '0';
			map[player->y + 1][player->x] = 'P';
			player->y++;
		}
	}
	else if (keycode == 97)
	{
		if (map[player->y][player->x - 1] != '1')
		{
			map[player->y][player->x] = '0';
			map[player->y][player->x - 1] = 'P';
			player->x--;
		}
	}
	else if (keycode == 100)
	{
		if (map[player->y][player->x + 1] != '1')
		{	
			map[player->y][player->x] = '0';
			map[player->y][player->x + 1] = 'P';
			player->x++;
		}
	}
	draw_map(param, map);
	if (keycode == 65307)
		dstroy(param);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	so_long;

	if (ac != 2)
		print_err("Map Not Found\n");
	parsing(&so_long, av[1]);
	so_long.mlx = mlx_init();
	if (!so_long.mlx)
		print_err("Can't Open\n");
	set_height_width(&so_long, so_long.map);
	so_long.mlx_win = mlx_new_window(so_long.mlx, so_long.map_width * 64,
			so_long.map_height * 64, "so_long");
	if (!so_long.mlx_win)
		mlx_clear_window(so_long.mlx, so_long.mlx_win);
	set_textures(&so_long);
	draw_map(&so_long, so_long.map);
	mlx_key_hook(so_long.mlx_win, key_hook, &so_long);
	mlx_hook(so_long.mlx_win, 17, 0, dstroy, &so_long);
	mlx_loop(so_long.mlx);
	ft_malloc(0, CLEAR);
}
