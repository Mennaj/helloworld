/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:58:27 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/12 15:25:54 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_char_convert(va_list args, char c)
{
	int	*count;

	count = 0;
	if (c == 'c')
		return (ft_putchar(args));
	else if (c == 's')
		ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		*count += ft_put_pointer(va_arg(args, unsigned int), c);
	else if (c == 'd' || c == 'i')
		*count += ft_putint(va_arg(args, int));
	else if (c == 'u')
		*count += ft_putuns(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		*count += ft_puthex_num(va_arg(args, unsigned int), c);
	if (c == '%')
		ft_putchar('%');
		*count += 1;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_char_convert(format[i], args);
		}
		else
		{
			write(1, format[i], 1);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
