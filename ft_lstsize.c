/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:25:09 by mennaji           #+#    #+#             */
/*   Updated: 2023/01/31 21:25:13 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst){
	int count;

	count = 0;
	while(lst){
		count++;
		lst = lst->next;
	}
	return (count);
}
