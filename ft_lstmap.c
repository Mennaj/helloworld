/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:58:34 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/03 11:59:02 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *)){
	t_list *new_list;
	t_list *tmp;
	t_list  *content = NULL;

    new_list = NULL;
    tmp = ft_lstnew(content);
	while(lst){
		content = f(lst->content);
         if (!(tmp = ft_lstnew(content))){
			ft_lstclear(&new_list, del);
			return NULL;
		 }
		 ft_lstadd_back (&new_list, tmp);
		 lst = lst->next; // lst is updated to point to the next node in the original linked lis
	}
	return(new_list);
}
