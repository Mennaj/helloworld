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
#include <stdio.h>
#include <string.h>

size_t	count_word(const char *s, char c)
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
	int		i;

	if(!s)
		return (NULL);
	ptr = (char **)malloc(sizeof(*ptr) * (count_word(s, c) + 1));
	if(!ptr){
		return (NULL);
	}
	i = 0;
	while(*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s){
			//allocate memory of copy of the word
				ptr[i] = ft_strdup(s, c);//and stores pointers in the arrays of pointers if non separator found
			if (!ptr[i])
				return (NULL);
			i++;
			while(*s && *s != c)
				s++;
		}
	}
	ptr[i] = 0;
	return (ptr);
}
