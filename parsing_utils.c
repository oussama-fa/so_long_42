/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:19:37 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/01 21:58:00 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (unsigned char)c)
			return ((char *)(s + len));
		len--;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s + len + 1));
	return (NULL);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	if (!n || !s1)
		return (1);
	while (*s1 && *s1 == *s2 && --n)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	print_err(char *s)
{
	while (*s)
		write(2, s++, 1);
	ft_malloc(0, CLEAR);
	exit(1);
}

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
