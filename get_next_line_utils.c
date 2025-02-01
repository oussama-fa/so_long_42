/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:56:42 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/01 03:30:08 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	if (!s1)
		return (NULL);
	s2 = malloc (ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (free(s1), NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		ret[i] = s1[i];
	while (s2[j])
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	free(s1);
	return (ret);
}
