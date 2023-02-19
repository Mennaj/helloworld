/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:11:36 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/19 19:10:50 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read_line(fd, buffer);
	if(!buffer)
		return (0);
	line = ft_get_line(buffer);
	buffer = ft_extract_remaining(buffer);
	return (line);
}

char *ft_read_line(int fd, char *box)
{
	char *buffer;
	int n;

	n = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if(!buffer)
		return (0);
	while(!ft_strchr(box, '\n') && n != 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if(n == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[n] = '\0';
		box = ft_strjoin(box, buffer);
	}
	free(buffer);
	return (box);

}
char *ft_get_line(char *buckup){
	char *string;
	char *new_line;
	char *ptr;
	size_t i;

	string = buckup;
	new_line = 0;
	i = 0;
	if(!*string || !string)
		return (0);
	while(string[i] && string[i] != '\n')
		i++;
	ptr = ft_strchr(string, '\n');
	i = ptr - string;
	// ptr = (char *) malloc(sizeof(char) * (i + 2));
	new_line = ft_substr(string, 0, i + 1);
	// if(!new_line)
	// 	return (0);
	// if(ft_strlen(string) > i && string[i] == '\n')
	// 	string++;
	// else if(string[i] == '\0' && i > 0)
	// 	string = 0;
	// free(new_line);
	return (new_line);
}

void *ft_extract_remaining(char *str){
	char *new_line;
	char *remaning;
	int i;

	i = 0;
	new_line = ft_strchr(str, '\n');
	if(!new_line)
		return (0);
	remaning = malloc(ft_strlen(new_line + 1) + 1);
	if(!remaning)
		return(0);
	ft_strlcpy(remaning, new_line + 1, ft_strlen(new_line + 1) + 1);
	return (remaning);
}
