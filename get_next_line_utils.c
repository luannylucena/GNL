/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:15:18 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/10/27 17:15:19 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	int		x;

	i = 0;
	x = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char *));
		s1 [0] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s1)) + 1);
	if (str == NULL || !s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[x] != '\0')
		str[i++] = s2[x++];
	free(s1);
	str[i] = '\0';
	return ((char *)str);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}