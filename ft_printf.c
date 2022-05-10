/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:51:40 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/09 19:27:45 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// int	countargs(const char *str)
// {
// 	int		i;
// 	int		count;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '%' && specifier(str[i + 1]))
// 			count++;
// 		i++;
// 	}
// 	return (count);	
// }

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
	else if (c == 'd')
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
	ft_printf("Hello %s \n", "Fanny");
	return 0;
}