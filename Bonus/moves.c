/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 04:30:15 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/06 11:33:24 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int x, int y)
{
	static int	moves;
	t_pos		*player;
	char		**map;
	int			new_x;
	int			new_y;

	player = &game->player;
	map = game->map;
	new_x = player->x + x;
	new_y = player->y + y;
	if (map[new_y][new_x] == 'E' && game->coin <= 0)
		(ft_putstr("You Win!\n"), dstroy(game));
	if (map[new_y][new_x] == 'V')
		(ft_putstr("You Lose\n"), dstroy(game));
	if (map[new_y][new_x] != '1' && map[new_y][new_x] != 'E')
	{
		if (map[new_y][new_x] == 'C')
			game->coin--;
		map[player->y][player->x] = '0';
		map[new_y][new_x] = 'P';
		player->x = new_x;
		player->y = new_y;
		moves++;
		ft_putstr("moves : ");
		ft_putnbr(moves);
		ft_putchar('\n');
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
		ft_putstr("Closed\n");
		dstroy(game);
	}
	draw_map(game, game->map, -1, -1);
	return (1);
}
