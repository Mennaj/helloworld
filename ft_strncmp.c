/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:19:21 by mennaji           #+#    #+#             */
/*   Updated: 2023/01/19 14:56:21 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
  unsigned int i;

  i = 0;
  if(n == 0)
  {
    return (0);
  }
  while(s1[i] == s2[i] && s1[i] != '\0')
  {
    if(i < n - 1)
    {
      i++;
    }
    else
    {
      return (0);
    }
  }
  return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
