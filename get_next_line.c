/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:11:36 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/16 18:13:22 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;
	int				count;

	list = 0;
	if (fd < 0 || read(fd, &line, 0) || BUFFER_SIZE > 0)
		return (0);
	count = 0;
	line = 0;
	read_list(fd, &list, &count);
	if(list == 0)
		return (0);

}
// this function read from fd and add to the linked list
void	read_list(int fd, t_list **list, int *readed)
{
	char *buf;
	t_list *ptr;
	int n;
	t_list *new_node;


	*readed = 0;
	ptr = *list;
	buf = malloc(BUFFER_SIZE);
	//read the bytes of data from the file fd and store it in buffer buf
	while(n = read(fd, buf, sizeof(BUFFER_SIZE)) > 0)
	{
		new_node = malloc(sizeof(t_list));// add a new node to the linked list using malloc
		new_node->content = malloc(n);// allocate memory for data of the new node
		ft_memcpy(new_node->next, buf, n); //copy nbyte from the buffer to new node
		new_node = 0; //set the new node to null
		if(!ptr)
		{
			//if is empty set the new head to the new node
			*list = new_node;
		}
		else{
			ptr->next = new_node; //add the new node to the end of the linked list
		}
		ptr = new_node; //update the pointer to the last node in the linked list
		*readed += n;
	}
	free(buf);
}
// function to find a new line
int		found_newline(t_list list){
	int i;
	t_list *current;

	i = 0;

}

