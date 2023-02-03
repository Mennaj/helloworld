/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 01:49:21 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/01 01:49:25 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new){
	t_list *current;
	if(!*lst){
		(*lst) = new;
		return ;
	}
	current = *lst;
	while (current->next){
		current = current->next;
	}
	current->next = new;
}
