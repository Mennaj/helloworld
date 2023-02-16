/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:58:12 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/16 15:39:48 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE
#endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}t_list;

char	*get_next_line(int fd);
int		found_newline(t_list list);
void	read_list(int fd, t_list **list, int *readed);
void	add_to_list(t_list **list, char *buf, int readed);
#endif
