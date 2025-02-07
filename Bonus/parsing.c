/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:49:23 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/07 12:46:56 by oufarah          ###   ########.fr       */
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
	ret = ft_malloc(len + 2, ALLOC);
	while (++i <= len)
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}

int	checkline_validity(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_strchr("10CPEV\n", s[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*mini_pars(char *av)
{
	t_game	pars;
	int		fd;
	char	*line;

	if (check_filename(av))
		print_err("Invalide Filename\n");
	fd = open(av, O_RDONLY);
	if (fd == -1)
		print_err("Can't Open File\n");
	line = get_next_line(fd);
	if (!line)
		(close(fd)), (print_err("Nothing To Read\n"));
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
	return (pars.join);
}

void	parsing(t_game *so_long, char *av)
{
	t_game	pars;
	t_pos	cor;
	char	**map_cpy;
	int		rows;

	pars.join = mini_pars(av);
	while (*pars.join == '\n')
		pars.join++;
	pars.join = skip_last(pars.join);
	if (check_line(pars.join) || check_validity_map(pars.join, so_long))
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
	so_long->map = pars.map;
	so_long->player = cor;
}
