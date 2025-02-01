/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:49:23 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/01 01:43:49 by oufarah          ###   ########.fr       */
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

// int	check_boarders(char *s)
int	check_boarders(char *s)
{
	int	hight;
	int	wight;
	int	i;

	i = 0;
	hight = 0;
	wight = 1;
	while (s[hight] != '\n')
	{
		if (s[hight] != '1')
			return (FALSE);
		hight++;
	}
	while (s[i])
	{
		if (s[i] == '\n')
			wight++;
		i++;
	}
	printf("H:[%d]\tW:[%d]\n", hight, wight);
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

void	parsing(char *av)
{
	char	*join;
	char	*line;
	int		fd;

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
	if (check_line(join) || check_validity_map(join) || check_boarders(join))
		print_err("Invalide Map\n");
	printf("%s", join);
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