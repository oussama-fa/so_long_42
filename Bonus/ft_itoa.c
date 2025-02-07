/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:33:26 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/08 00:16:15 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (!s)
		write(1, "(null)", 6);
	while (s[++i])
		write(1, &s[i], 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		ft_putnbr(nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb <= 10)
		ft_putchar(nb + 48);
}

static size_t	lenght(long nb)
{
	size_t	i;

	i = 0;
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	int		flag;
	char	*s;

	(1) && (flag = 0, num = n, len = lenght(num));
	if (!n)
		return (ft_strdup("0"));
	else if (num < 0)
		(1) && (len++, flag = 1, num *= -1);
	s = ft_malloc (len + 1, ALLOC);
	if (flag == 1)
		s[0] = '-';
	s[len] = '\0';
	len--;
	while (len >= flag)
	{
		s[len] = num % 10 + 48;
		num /= 10;
		len--;
	}
	return (s);
}
