/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:05:17 by mennaji           #+#    #+#             */
/*   Updated: 2023/01/17 08:31:37 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isalnum(int arg)
{
	if(ft_isalpha(arg) || ft_isdigit(arg))
		return(1);
	return(0);
}

