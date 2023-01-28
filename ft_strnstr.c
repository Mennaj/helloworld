/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:49:45 by mennaji           #+#    #+#             */
/*   Updated: 2023/01/19 19:45:01 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
      size_t	i;
	  size_t	j;
	  if (*needle == '\0' || needle == NULL)
	  {
		return(char*)haystack;
	  }
	  i=0;
	  while (i < len && haystack != '\0')
	  {
		j=0;
		while (needle[j] == haystack[i+j] && i+j < len)
		{
			if (needle[j+1] == '\0')
				{
					return ((char*)haystack + i);
				}
				j++;
			}
			i++;
		}
		return (NULL);
}
