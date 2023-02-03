/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:40:44 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/01 15:40:47 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next; //TO STORE THE NEXTNODE IN THE LIST BEFORE FREEING THE CURRENT NODE
	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	current = *lst;
    while(current != NULL)
	{
		next= current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
