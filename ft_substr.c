/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:26:07 by mennaji           #+#    #+#             */
/*   Updated: 2023/01/23 12:26:09 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*string;
	char			*ptr;
	unsigned int	i;

	i = 0;
	string = (char *)s;
	ptr = (char *)malloc (sizeof(char) * (len + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i < len && string[i] != '\0')
	{
		ptr[i] = string[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
