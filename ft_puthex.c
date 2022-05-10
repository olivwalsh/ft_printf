/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:26:10 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/10 17:56:08 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	charcount(int nb, char *base)
{
	int	i;
	int	baselen;

	i = 1;
	baselen = ft_strlen(base);
	while (nb >= baselen)
	{
		nb = nb / baselen;
		i++;
	}
	return (i);
}

void	putnbr_base(int nb, char *base)
{
	int	baselen;

	baselen = ft_strlen(base);
	if (nb >= baselen)
		putnbr_base((nb / baselen), base);
	ft_putchar(base[nb % baselen]);
}

int	ft_puthex(int i)
{
	char	*base;
	int		sum;

	base = "0123456789abcdef";
	sum = 0;
	if (i < 0)
	{
		ft_putchar('-');
		sum++;
	}
	putnbr_base(i, base);
	sum += charcount(i, base);
	return (sum);	
}

int	ft_putHEX(int i)
{
	char	*base;
	int		sum;

	base = "0123456789ABCDEF";
	sum = 0;
	if (i < 0)
	{
		ft_putchar('-');
		sum++;
	}
	putnbr_base(i, base);
	sum += charcount(i, base);
	return (sum);	
}