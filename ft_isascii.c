/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:55:22 by mennaji           #+#    #+#             */
/*   Updated: 2023/01/24 03:55:26 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libft.h"

int ft_isascii(int arg)
{
  return(arg >=0 && arg<=127);
}
