/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:38:54 by mennaji           #+#    #+#             */
/*   Updated: 2023/01/23 17:46:03 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2){

  int i;
  int j;
  char *ptr;
  char *str1;
  char *str2;
  size_t sumSize;

  str1 = (char*)s1;
  str2 = (char*)s2;
  sumSize = ft_strlen(str1) + ft_strlen(str2);
  ptr = (char*)malloc(sumSize);
 if(ptr == NULL){
  return NULL;
 }
  i = 0;
  j = 0;
  while(s1[i]){
	ptr[j] = s1[i];
	i++;
	j++;
  }
  i = 0;
  while(s2[i]){
       ptr[j] = s2[i];
	   j++;
	   i++;
  }
  ptr[j] = '\0';
  return(ptr);
}

