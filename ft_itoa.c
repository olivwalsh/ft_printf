/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:16:49 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/09 19:25:02 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static long	countdigits(long n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	putnbr(long n, char *str, int size)
{
	if (n > 9)
		putnbr(n / 10, str, size - 1);
	*(str + size) = n % 10 + '0';
}

int	ft_itoa(int n)
{
	char	*str;
	long	l;
	int		size;

	size = 0;
	l = n;
	if (l < 0)
	{
		l *= -1;
		size += 1;
	}
	size += countdigits(l);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	if (n < 0)
		str[0] = '-';
	putnbr(l, str, size - 1);
	str[size] = '\0';
	ft_putstr(str);
	return (5);
}
