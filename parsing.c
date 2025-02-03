/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:49:23 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/03 01:16:12 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*skip_last(char *s)
{
	int		len;
	int		i;
	char	*ret;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	len--;
	i = -1;
	while (s[len] && s[len] == '\n')
		len--;
	ret = ft_malloc(len + 1, ALLOC);
	while (++i <= len)
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1')
		return ;
	map[y][x] = '1';
	flood_fill(map, y - 1, x);
	flood_fill(map, y + 1, x);
	flood_fill(map, y, x - 1);
	flood_fill(map, y, x + 1);
}

void	check_valid_path(char **map_cpy, int y, int x)
{
	int	tmpx;

	while (map_cpy[y])
	{
		tmpx = x;
		while (map_cpy[y][tmpx])
		{
			if (map_cpy[y][tmpx] == 'C' || map_cpy[y][tmpx] == 'E')
				return (print_err("Invalide Path\n"));
			tmpx++;
		}
		y++;
	}	
}

t_pos	get_player_pos(char **map)
{
	t_pos	cor;

	cor.y = 0;
	while (map[cor.y])
	{
		cor.x = 0;
		while (map[cor.y][cor.x])
		{
			if (map[cor.y][cor.x] == 'P')
				return (cor);
			cor.x++;
		}
		cor.y++;
	}
	return (cor);
}

int	checkline_validity(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_strchr("10CPE\n", s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	parsing(char *av)
{
	t_game	pars;
	t_pos	cor;
	char	**map_cpy;
	char	*line;
	int		fd;
	int		rows;

	if (check_filename(av))
		print_err("Invalide Filename\n");
	fd = open(av, O_RDONLY);
	if (fd == -1)
		print_err("Can't Open File\n");
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		print_err("Nothing To Read\n");
	}
	pars.join = ft_strdup("");
	while (line)
	{		
		pars.join = ft_strjoin(pars.join, line);
		line = get_next_line(fd);
		if (line && !checkline_validity(line))
		{
			close(fd);
			print_err("Invalide Map\n");
		}
	}
	close(fd);
	while (*pars.join == '\n')
		pars.join++;
	pars.join = skip_last(pars.join);
	if (check_line(pars.join) || check_validity_map(pars.join))
		print_err("Invalide Map\n");
	pars.map = ft_split(pars.join, '\n');
	map_cpy = ft_split(pars.join, '\n');
	rows = 0;
	while (pars.map[rows])
		rows++;
	if (!is_map_valid(pars.map, rows))
		print_err("Invalide Map\n");
	cor = get_player_pos(map_cpy);
	flood_fill(map_cpy, cor.y, cor.x);
	check_valid_path(map_cpy, 0, 0);
}
