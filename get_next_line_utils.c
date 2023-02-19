/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:01:13 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/19 18:54:07 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)src;
	src_len = ft_strlen(str);
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	size_t		len;
	char		*ptr;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (0);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[j + i] = s2[j];
		j++;
	}
	ptr[j + i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*string;
	char			*ptr;
	size_t			i;
	size_t			slen;

	i = 0;
	string = (char *)s;
	slen = ft_strlen(string);
	/*if (start >= slen)
		return (ft_strdup(""));*/
	if (slen - start < len)
		len = slen - start;
	ptr = (char *)malloc (sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (i < len && string[start + i] != '\0')
	{
		ptr[i] = string[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
char	*ft_strchr(const char *str, int ch)
{
	if (!str)
		return (0);
	while (*str != '\0')
	{
		// printf("im in strchr!\n");
		if (*str == (char)ch)
			return ((char *)str);
		str++;
	}
	if ((char)ch == 0)
	{
		return ((char *)str);
	}
	return (0);
}



