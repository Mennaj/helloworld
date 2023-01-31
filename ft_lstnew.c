/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:47:08 by mennaji           #+#    #+#             */
/*   Updated: 2023/01/31 18:47:11 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
      t_list *new_node;

	  new_node = (t_list *) malloc(sizeof(t_list));
	  if(!new_node){
		return (NULL);
	  }
	  new_node->content = content;
	  new_node->next = NULL;
	  return(new_node);
}
