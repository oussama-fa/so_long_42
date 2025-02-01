/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:49:23 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/01 22:07:55 by oufarah          ###   ########.fr       */
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

// void flood_fill(char **map,int y, int x)
// {
// 	if(map[y][x] == '1' || map[y][x] == 'X' || map[y][x] == 'R')
// 		return;
// 	if(map[y][x] == 'E')// close exit
// 	{
// 		map[y][x] = 'R';
// 		return;
// 	}
// 	map[y][x] = 'X';
// 	flood_fill(map,y-1,x); 
// 	flood_fill(map,y+1,x); 
// 	flood_fill(map,y,x-1);
// 	flood_fill(map,y,x+1);
// }
// int check_path(char **map)
// {
// 	int size = 0;
// 	char **cp_map;
// 	while(map[size])
// 		size++;
// 	cp_map = ft_malloc(sizeof(char *) * (size + 1),ALLOC);
// 	int i = -1;
// 	while(map[++i])
// 		cp_map[i] = map[i];
// 	cp_map[i] = NULL;
// 	flood_fill(cp_map,get_player_pos(map)[0],get_player_pos(map)[1]);
// 	return(0);
// }
void	parsing(char *av)
{
	char	*join;
	char	**map;
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
	rows = 0;
	while (map[rows])
		rows++;
	if (!is_map_valid(map, rows))
		print_err("Invalide Map\n");
	// check_path(map);
}
