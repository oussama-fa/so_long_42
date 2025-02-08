/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:56:54 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/08 22:22:53 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_do(t_game *game, int new_y, int new_x)
{
	int static	moves;
	t_pos		*player;

	player = &game->player;
	if (game->map[new_y][new_x] == 'E' && game->coin <= 0)
		(ft_putstr("You Win!\n"), dstroy(game), ft_malloc(0, CLEAR));
	if (game->map[new_y][new_x] == 'V')
		(ft_putstr("You Lose\n"), dstroy(game), ft_malloc(0, CLEAR));
	if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'E')
	{
		if (game->map[new_y][new_x] == 'C')
			game->coin--;
		game->map[player->y][player->x] = '0';
		game->map[new_y][new_x] = 'P';
		moves++;
		game->moves = moves;
		ft_putstr("moves : ");
		ft_putnbr(moves);
		ft_putchar('\n');
		player->x = new_x;
		player->y = new_y;
	}
}

void	move_player(t_game *game, int x, int y)
{
	t_pos		*player;
	char		**map;
	int			new_x;
	int			new_y;

	player = &game->player;
	map = game->map;
	new_x = player->x + x;
	new_y = player->y + y;
	if (x == 0 && y == -1)
		game->texture.player = game->texture.player_up;
	else if (x == 0 && y == 1)
		game->texture.player = game->texture.player_down;
	else if (x == -1 && y == 0)
		game->texture.player = game->texture.player_left;
	else if (x == 1 && y == 0)
		game->texture.player = game->texture.player_right;
	player_do(game, new_y, new_x);
}

int	game_loop(t_game *game)
{
	static int	i;

	if (i == 1000)
	{
		move_enemy(game);
		i = 0;
		draw_map(game, game->map, -1, -1);
	}
	else
		i++;
	draw_it(game);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		ft_putstr("Closed\n");
		dstroy(game);
	}
	else if (keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 115)
		move_player(game, 0, 1);
	else if (keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 100)
		move_player(game, 1, 0);
	draw_map(game, game->map, -1, -1);
	return (1);
}
