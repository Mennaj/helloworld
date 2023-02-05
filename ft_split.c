/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:28:03 by mennaji           #+#    #+#             */
/*   Updated: 2023/01/30 20:28:06 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		while(*s != c && *s)
			s++;
		if (*s == c){
			count++;
			while (*s == c && *s)
				s++;
		}
	}
	if (*(s - 1) == c)
			count--;
	return (count + 1);
}

char	**ft_split(char const *s, char c){
	char	**ptr;
	size_t	i;
	size_t len;

	if(!s)
		return (NULL);
	ptr = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if(!ptr)
		return (NULL);
	i = 0;
	while(*s)
	{
		if(*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			ptr[i++] = ft_substr(s- len, 0, len);
		}
		else
			s++;
	}
	ptr[i] = 0;
	return (ptr);
}
