/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:43:13 by mennaji           #+#    #+#             */
/*   Updated: 2023/01/19 12:45:12 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*charFind;

	charFind = NULL;
	while (*str)
	{
		if(*str == (char)ch)
		{
			charFind = (char *)str;
		}
		str++;
	}
    if(ch == 0){
		return (char*)str;
	}
	return charFind;
}
