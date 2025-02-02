/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:49:23 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/02 23:24:10 by oufarah          ###   ########.fr       */
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
	while (map_cpy[y])
	{
		while (map_cpy[y][x])
			if (ft_strchr("10", map_cpy[y][x++]))
				return (print_err("Invalide Path\n"));
		y++;
	}	
}

void	parsing(char *av)
{
	char	*join;
	char	**map;
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
		print_err("Nothing To Read\n");
	join = ft_strdup("");
	while (line)
	{		
		join = ft_strjoin(join, line);
		line = get_next_line(fd);
	}
	close(fd);
	while (*join == '\n')
		join++;
	join = skip_last(join);
	if (check_line(join) || check_validity_map(join))
		print_err("Invalide Map\n");
	map = ft_split(join, '\n');
	map_cpy = ft_split(join, '\n');
	rows = 0;
	while (map[rows])
		rows++;
	if (!is_map_valid(map, rows))
		print_err("Invalide Map\n");
	// flood_fill(map_cpy, y, x);
	// check_valid_path(map_cpy, y, x);
}
