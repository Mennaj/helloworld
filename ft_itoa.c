/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:12:10 by mennaji           #+#    #+#             */
/*   Updated: 2023/01/29 19:30:22 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MAXLINE 1000

int	digit_count(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		d_count;
	char	*ptr;

	d_count = digit_count(n);
	ptr = (char *)ft_calloc(d_count + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	ptr[d_count--] = 0;
	while (d_count >= 0 && ptr[d_count] != '-')
	{
		ptr[d_count--] = abs(n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}
