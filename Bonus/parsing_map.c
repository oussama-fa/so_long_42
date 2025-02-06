/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 04:54:15 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/06 11:36:51 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(char *s)
{
	if (!s)
		return (FALSE);
	while (*s)
	{
		if (*s == '\n' && *(s + 1) == '\n')
			return (FALSE);
		s++;
	}
	return (TRUE);
}

int	check_validity_map(char *s, t_game *so_long)
{
	int	count_p;
	int	count_e;
	int	count_c;
	int	count_v;
	int	i;

	i = -1;
	count_p = 0;
	count_e = 0;
	count_c = 0;
	count_v = 0;
	while (s[++i])
	{
		if (s[i] == 'P')
			count_p++;
		else if (s[i] == 'E')
			count_e++;
		else if (s[i] == 'C')
			count_c++;
		else if (s[i] == 'V')
			count_v++;
	}
	if (count_e != 1 || count_p != 1 || count_c < 1 || count_v < 1)
		return (FALSE);
	so_long->coin = count_c;
	so_long->enemy_count = count_v;
	return (TRUE);
}

int	check_same_len(char **map, int rows)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = -1;
	while (++i < rows)
	{
		if (ft_strlen(map[i]) != len)
			return (FALSE);
	}
	return (TRUE);
}

int	check_walls(char **map, int rows, int cols)
{
	int	j;
	int	i;

	j = -1;
	while (++j < cols)
	{
		if (map[0][j] != '1' || map[rows - 1][j] != '1')
			return (FALSE);
	}
	i = 0;
	while (++i < rows - 1)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (FALSE);
	}
	return (TRUE);
}

int	is_map_valid(char **map, int rows)
{
	int	cols;

	cols = ft_strlen(map[0]);
	if (check_same_len(map, rows))
		return (TRUE);
	if (check_walls(map, rows, cols))
		return (TRUE);
	return (FALSE);
}
