/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:49:23 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/01 05:01:44 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_filename(char *str)
{
	int		len;
	char	*here;

	here = ft_strrchr(str, '.');
	len = 0;
	while (str[len])
	{
		if (!ft_strncmp(here, ".ber\0", 5))
			return (TRUE);
		len++;
	}
	return (FALSE);
}

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
	ret = malloc(len + 1);
	while (++i <= len)
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}

void	free_map(char **map, int rows)
{
	int	i;

	i = -1;
	while (++i < rows)
		free(map[i]);
	free(map);
}

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
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	while (*join == '\n')
		join++;
	join = skip_last(join);
	if (check_line(join) || check_validity_map(join))
		print_err("Invalide Map\n");
	map = ft_split(join, '\n');
	if (!map)
		return ;
	free(join);
	rows = 0;
	while (map[rows])
		rows++;
	if (!is_map_valid(map, rows))
		print_err("Invalide Map\n");
	free_map(map, rows);
}
