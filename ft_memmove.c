/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:02:43 by mennaji           #+#    #+#             */
/*   Updated: 2023/01/17 17:30:56 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t		i;
	char	    *ptr1;
	char 	    *ptr2;

	i = 0;
	ptr1 = (char *)dest;
	ptr2 = (char *)src;
	if(!dest && !src){
		return (dest);
	}
	if(ptr1 > ptr2)
	{
		while(len--)
		{
			 ptr1[len] = ptr2[len];
		}
	}
	else{
		while(i<len)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	}
	return (dest);
}

