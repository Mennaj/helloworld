/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:41:34 by mennaji           #+#    #+#             */
/*   Updated: 2023/01/24 03:41:38 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libft.h"


int	ft_isalpha(int c)
{
	if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	else{
		return (0);
	}
}
