/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:11:36 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/18 15:39:09 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buf[BUFFER_SIZE];
	char			*line;
	int				count;

	if (fd < 0 || (BUFFER_SIZE) >= 0)
		return (0);
	count = 0;
	line = 0;
	read_line(fd, &buf, &count);
	if(buf == 0)
		return (0);

}
void read_line(int fd, char *box, int *readed)
{
	char *buf;
	int n;

	buf = malloc(BUFFER_SIZE);
	*readed = 0;//keep track of how many bytes have been read from the file
	while(n = read(fd, buf, BUFFER_SIZE) > 0){
		ft_memcpy(box + *readed, buf, n);
		*readed += n;
	}

}
void get_line(char *buckup){
	static char *string;
	char new_line;
	int i;

	string = buckup;
	i = 0;
	if(!*string)
		return (0);
	while(string[i] && string[i] != '\n')
		i++;
	new_line = ft_substr(string, 0, i);
	string += i;
	if(ft_strlen(string) > i && string[i] == '\n')
		string++;
	return (new_line);

}
void *extract_remaining(char *str){
	char *new_line;
	char *remaning;

	new_line = ft_strchr(str, '\n');
	if(!new_line)
		return (0);
	remaning = malloc(ft_strlen(new_line + 1) + 1);
	if(!remaning)
		return(0);
	ft_strlcpy(remaning, new_line + 1, ft_strlen(new_line + 1) + 1);
	return (remaning);
}

