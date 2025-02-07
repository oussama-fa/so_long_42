/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 04:30:15 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/07 14:09:37 by oufarah          ###   ########.fr       */
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
		if (new_x >= 0 && new_x < game->map_width && new_y >= 0
			&& new_y < game->map_height && (game->map[new_y][new_x] != '1'
			&& game->map[new_y][new_x] != 'C'
			&& game->map[new_y][new_x] != 'E'))
		{
			if (game->map[new_y][new_x] == 'P')
				(ft_putstr("You Lose\n"), dstroy(game));
			game->map[game->enemy[i].y][game->enemy[i].x] = '0';
			game->map[game->enemy[i].y][game->enemy[i].x] = 'V';
			game->enemy[i].x = new_x;
			game->enemy[i].y = new_y;
		}
	}
}

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
		game->moves = moves;
		ft_putstr("moves : ");
		ft_putnbr(moves);
		ft_putchar('\n');
		draw_map(game, game->map, player->y, player->x);
	}
}

int	game_loop(t_game *game)
{
	static int	i;

	if (i == 20000)
	{
		move_enemy(game);
		i = 0;
		draw_map(game, game->map, -1, -1);
	}
	else
		i++;
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
	// draw_map(game, game->map, -1, -1);
	return (1);
}
