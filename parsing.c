/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:49:23 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/01 04:27:40 by oufarah          ###   ########.fr       */
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

int	check_validity_map(char *s)
{
	int	count_p;
	int	count_e;
	int	count_c;
	int	i;

	i = -1;
	count_p = 0;
	count_e = 0;
	count_c = 0;
	while (s[++i])
	{
		if (s[i] == 'P')
			count_p++;
		else if (s[i] == 'E')
			count_e++;
		else if (s[i] == 'C')
			count_c++;
	}
	if (count_e != 1 || count_p != 1 || count_c < 1)
		return (FALSE);
	return (TRUE);
}

void	free_map(char **map, int rows)
{
	int	i;

	i = -1;
	while (++i < rows)
		free(map[i]);
	free(map);
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
			return (FALSE); // Top or bottom wall is missing
	}
	i = 0;
	while (++i < rows - 1)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (FALSE); // Left or right wall is missing
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
		return ; // error handling
	free(join);
	rows = 0;
	while (map[rows])
		rows++;
	if (!is_map_valid(map, rows))
		print_err("Invalide Map\n");
}

// jisos

// int check_filename(char *str)
// {
// 	int size = ft_strlen(str);
// 	if(size < 4)
// 		return(FALSE);
// 	if((str[size-1] == 'r' && str[size-2] == 'e'
// 		 && str[size-3] == 'b' && str[size-4] == '.'))
// 		return(TRUE);
// 	return (FALSE);
// }