/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:48:54 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/04 08:44:24 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	so_long;

	so_long.coin = 0;
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
		mlx_destroy_window(so_long.mlx, so_long.mlx_win);
		mlx_destroy_display(so_long.mlx);
		print_err("Closed!\n");
	}
	set_textures(&so_long);
	mlx_key_hook(so_long.mlx_win, key_hook, &so_long);
	mlx_hook(so_long.mlx_win, 17, 0, dstroy, &so_long);
	mlx_loop(so_long.mlx);
	free_textures(&so_long);
	mlx_destroy_display(so_long.mlx);
	ft_malloc(0, CLEAR);
}
