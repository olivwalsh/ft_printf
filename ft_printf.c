/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:51:40 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/10 18:05:38 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	specifier(char c)
{
	char	*specifiers;
	int		i;
	
	specifiers = "cspdiuxX%";
	i = 0;
	while (specifiers[i])
	{
		if (c == specifiers[i])
			return (1);
		i++;
	}
	return (0);
}

int	callspecifier(char c, va_list args)
{	
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, int)));
	else if (c == 'X')
		return (ft_putHEX(va_arg(args, int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(args, int)));
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list	args;
    int		i;
	int		sum;

    if (!str) 
        return (0);
    va_start(args, str);
	i = 0;
	sum = 0;
	while (str[i])
	{
		if (str[i] == '%' && specifier(str[i + 1]))
		{
			sum += callspecifier(str[i + 1], args);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			sum++;
		}
		i++;
	}
	va_end(args);
	return (sum);	
}

int	main(void)
{
	printf("Hello %i\n", 42);
	ft_printf("Hello %i \n", 42);
	return 0;
}