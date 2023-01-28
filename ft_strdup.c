/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:42:28 by mennaji           #+#    #+#             */
/*   Updated: 2023/01/23 09:42:31 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *ch)
{
	int		n;
	int		i;
	char	*ptr;
	char	*tmp;

	n = strlen(ch);
	i = 0;
	ptr = (char *)ch;
	tmp = (char *) malloc(n * sizeof(char));
	if (!tmp)
	{
		return (NULL);
	}
	while (*ch)
	{
		tmp[i] = *ch;
		i++;
		ch++;
	}
	ptr = 0;
	return (tmp);
}
