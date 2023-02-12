/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:52:12 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/09 10:43:14 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_num(char c, unsigned int n)
{
	char	*base;

	if (n >= 16)
		ft_puthex_num(c, n / 16);
	if (c == 'x' || c == 'X')
		base = "0123456789abcdef";
	ft_putchar(base[n % 16]);
}

int	ft_put_pointer(char c, unsigned int n)
{
	char	*base;

	if (n >= 16)
		ft_puthex_num(c, n / 16);
	if (c == 'p')
	{
		c = 'x';
		write(1, "0x", 2);
	}
	if(n > 0)
		ft_put_pointer(c, n);
	base = "0123456789abcdef";
	ft_putchar(base[n % 16]);
}

int	ft_putuns(unsigned int n)
{
	if (n >= 10)
		ft_putnbr_uns(n / 10);
	ft_putchar(n % 10 + '0');
}

int	ft_putint(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putint(n / 10);
	ft_putchar(n % 10 + 48);
}
