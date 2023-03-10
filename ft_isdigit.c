/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:45:05 by mennaji           #+#    #+#             */
/*   Updated: 2023/01/24 03:45:10 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ctype.h>

int	ft_isdigit(int arg)
{
	return(arg >= '0' && arg <= '9');
}

