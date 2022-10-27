/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:12:43 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/10/27 18:09:32 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*read_line(int fd, char *store_rest)
{
	char	*buf;
	int		read_byte;

	buf = (char *)malloc(sizeof(char *) * BUFFER_SIZE + 1);
	read_byte = 1;
	while (!ft_strchr(store_rest, '\n') && read_byte != 0)
	{	
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_byte] = '\0';
		store_rest = ft_strjoin(store_rest, buf);
	}
	free(buf);
	return (store_rest);
}

static char	*separate_line(char *store_rest)
{
	int		i;
	int		c;
	char	*after_n;

	i = 0;
	while (store_rest[i] && store_rest[i] != '\n')
		i++;
	if (!store_rest[i])
	{
		free(store_rest);
		return (NULL);
	}
	after_n = (char *)malloc(sizeof(char) * (ft_strlen(store_rest) - i + 1));
	if (!after_n)
		return (NULL);
	i++;
	c = 0;
	while (store_rest[i])
		after_n[c++] = store_rest[i++];
	after_n[c] = '\0';
	free(store_rest);
	return (after_n);
}

static char	*print_first_line(char *store_rest)
{
	int		i;
	char	*line;

	i = 0;
	if (!store_rest[i])
		return (NULL);
	while (store_rest[i] && store_rest[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (store_rest[i] && store_rest[i] != '\n')
	{
		line[i] = store_rest[i];
		i++;
	}
	if (store_rest[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*store_rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store_rest = read_line(fd, store_rest);
	if (!store_rest)
	{
		free(store_rest);
		return (NULL);
	}
	line = print_first_line(store_rest);
	store_rest = separate_line(store_rest);
	if (!line)
	{
		free(store_rest);
		free(line);
		return (NULL);
	}
	return (line);
}

int main()
{
    int fd;
    char *line;

    line = "";
    
    fd = open("texte.txt", O_RDONLY);
    
    while(line != 0)
    {
        line = get_next_line(fd);
        printf("%s", line);
    }
    close(fd);
    return (0);
}