/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:46:52 by mennaji           #+#    #+#             */
/*   Updated: 2023/01/27 15:46:55 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "libft.h"

int	check_set(char str, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if(set[i++] == c)
			return (1);
	}
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int	    start;
	int	    end;
	int	    i;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	if(s1 == 0 || set == 0){
		return (NULL);
	}
	while (s1[start] && check_set(s1[start], set))
	{
		start++;
	}
	while (end > start && check_set(s1[end - 1], set))
	{
		end--;
	}
	str = (char *) malloc(sizeof(char) * (end - start + 1))
	while (start < end)
		str[i++]  = s1[start++];
	str[i] = '\0';
	return (str);
}*/


/*#include "libft.h"

int get_the_firt(char const *s){
	 int i;

	 i = 0;
	 while(s[i] == ' ' || s[i] == '\t' || s[i] == '\n'){
		i++;
	 }
	 return (i);

int get_the_last(char const *s)
	 int i;

	 i = ft_strlen(s);
	 while(s[i] == ' ' || s[i] == '\t' || s[i] == '\n'){
		i--;
	 }
	 return (i);
}*/

/*int get_trim_len(char const *str)
    return (get_last_position(str) - get_first_position(str));

char *ft_strtrim(char const *s1, char const *set)
{
	char *ptr;
	int start;
	int end;
	int i;

	i = 0;
	start = get_trim_len(s) + 1;
	ptr = NULL;
	if(!s1 || !set){
		return (NULL);..
	}

	while(start < end){
		ptr[i] = s1[start];

		i++;
		start++;
	}
	ptr[i] = 0;
	return (ptr);
}*/

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	char *ptr;
	int start;
	int end;
	int count;


	count = 0;
	start = 0;
	end  = ft_strlen((char *)s1);
	if(!s1  && !set){
		return (NULL);
	}
	while(ft_strchr(set, s1[start]) && end > start)
	{
		start++;
	}
	while(ft_strchr(set, s1[end - 1]) && start < end)
	{
		end--;
	}
	/*ptr = (char *)malloc(sizeof(char) * (end - start + 1));*/
	ptr = malloc(end - start + 1);
	if(!ptr){
		return (NULL);
	}
	while(start < end){
		ptr[count] = s1[start];
		count++;
		start++;
	}
	ptr[count] = 0;
	return (ptr);
}
