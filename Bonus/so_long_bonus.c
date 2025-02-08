/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:48:54 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/08 12:25:40 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_logic(t_game *so_long)
{
	enemy_position(so_long);
	set_textures(so_long);
	draw_map(so_long, so_long->map, -1, -1);
	mlx_key_hook(so_long->mlx_win, key_hook, so_long);
	mlx_hook(so_long->mlx_win, 17, 0, dstroy, so_long);
	game_loop(so_long);
	mlx_loop_hook(so_long->mlx, game_loop, so_long);
	mlx_loop(so_long->mlx);
}

int	main(int ac, char **av)
{
	t_game	so_long;

	so_long.coin = 0;
	if (ac != 2)
		print_err("Invalide Input\n");
	parsing(&so_long, av[1]);
	so_long.mlx = mlx_init();
	if (!so_long.mlx)
		print_err("Can't Open\n");
	set_height_width(&so_long, so_long.map);
	if (so_long.map_height > 30 || so_long.map_width > 60)
		print_err("Map To Larg\n");
	so_long.mlx_win = mlx_new_window(so_long.mlx, so_long.map_width * 64,
			so_long.map_height * 64, "so_long");
	if (!so_long.mlx_win)
	{
		mlx_destroy_window(so_long.mlx, so_long.mlx_win);
		mlx_destroy_display(so_long.mlx);
		print_err("Closed!\n");
	}
	so_long.moves = 0;
	game_logic(&so_long);
	mlx_destroy_display(so_long.mlx);
	free_textures(&so_long);
	ft_malloc(0, CLEAR);
}

void	draw_it(t_game *so_long)
{
	char	*mov;
	int		height;
	int		width;

	so_long->texture.first_wall = mlx_xpm_file_to_image(so_long->mlx,
			"Bonus/textures/move_1.xpm", &width, &height);
	so_long->texture.secend_wall = mlx_xpm_file_to_image(so_long->mlx,
			"Bonus/textures/move_2.xpm", &width, &height);
	if (!so_long->texture.first_wall || !so_long->texture.secend_wall)
		dstroy(so_long);
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
		so_long->texture.first_wall, 0 * 64, 0 * 64);
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
		so_long->texture.secend_wall, 1 * 64, 0 * 64);
	mov = ft_itoa(so_long->moves);
	if (!mov)
		return ;
	mlx_string_put(so_long->mlx, so_long->mlx_win,
		15, 40, 0xFFFFFF, "M O V E S :");
	mlx_string_put(so_long->mlx, so_long->mlx_win, 100, 40, 0xFF0000, mov);
	mlx_destroy_image(so_long->mlx, so_long->texture.first_wall);
	mlx_destroy_image(so_long->mlx, so_long->texture.secend_wall);
}

void	destroy_and_free(void *mlx, void *ptr)
{
	mlx_destroy_image(mlx, ptr);
}

void	free_textures(t_game *game)
{
	if (game->texture.player_down)
		destroy_and_free(game->mlx, game->texture.player_down);
	if (game->texture.player_up)
		destroy_and_free(game->mlx, game->texture.player_up);
	if (game->texture.player_right)
		destroy_and_free(game->mlx, game->texture.player_right);
	if (game->texture.player_left)
		destroy_and_free(game->mlx, game->texture.player_left);
	if (game->texture.wall)
		destroy_and_free(game->mlx, game->texture.wall);
	if (game->texture.collect)
		destroy_and_free(game->mlx, game->texture.collect);
	if (game->texture.exit_closed)
		destroy_and_free(game->mlx, game->texture.exit_closed);
	if (game->texture.exit)
		destroy_and_free(game->mlx, game->texture.exit);
	if (game->texture.space)
		destroy_and_free(game->mlx, game->texture.space);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
}
