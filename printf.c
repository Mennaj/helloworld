/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:58:27 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/07 11:53:57 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_convert(char c, int *count, va_list args)
{
	if (c == 'c'){
		ft_putchar(va_end(int, args));
		*count += 1;
	}
	else if (c == 's')
		*count += ft_putstr(args);
	else if (c == 'p')
		*count += ft_putnbr_hex(args);
}
int	ft_printf(const char *format, ...){
	va_list  args;
	int i;
	int count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i]){
		if (format[i] == "%"){
			i++;
			ft_char_convert(format[i], count, args);
		}
		else{
			write(1, format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (i);
}
