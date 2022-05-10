#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_itoa(int i);

#endif
