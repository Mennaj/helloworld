/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:00:18 by mennaji           #+#    #+#             */
/*   Updated: 2023/01/19 12:42:04 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	while (*str != '\0')
	{
		if (*str == ch)
		{
			return (char *)str;
		}
		str++;
	}
	if(ch == 0)
	{
		return (char *)str;
	}
	return NULL;
}
