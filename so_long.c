/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:48:54 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/04 04:03:49 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int x, int y)
{
	t_pos	*player;
	char	**map;
	int		new_x;
	int		new_y;

	player = &game->player;
	map = game->map;
	new_x = player->x + x;
	new_y = player->y + y;
	if (map[new_y][new_x] != '1')
	{
		map[player->y][player->x] = '0';
		map[new_y][new_x] = 'P';
		player->x = new_x;
		player->y = new_y;
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 115)
		move_player(game, 0, 1);
	else if (keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 100)
		move_player(game, 1, 0);
	else if (keycode == 65307)
	{
		dstroy(game);
		print_err("Closed!\n");
		exit(0);
	}
	draw_map(game, game->map, -1, -1);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	so_long;

	so_long.moves = 0;
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
	{
		mlx_clear_window(so_long.mlx, so_long.mlx_win);
		print_err("Closed!\n");
	}
	set_textures(&so_long);
	draw_map(&so_long, so_long.map, -1, -1);
	mlx_key_hook(so_long.mlx_win, key_hook, &so_long);
	mlx_hook(so_long.mlx_win, 17, 0, dstroy, &so_long);
	mlx_loop(so_long.mlx);
	ft_malloc(0, CLEAR);
}
