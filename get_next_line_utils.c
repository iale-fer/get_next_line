/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanalefernandez <ivanalefernandez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:03:41 by ivanalefern       #+#    #+#             */
/*   Updated: 2023/05/01 13:23:00 by ivanalefern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{	
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*c;
	size_t	i;

	i = 0;
	c = malloc(count * size);
	if (c == NULL)
		return (NULL);
	while (i < count * size)
	{
		c[i] = 0;
		i++;
	}
	return (c);
}

char	*ft_strjoin(char *readed, char *buffer)
{
	char	*jointed;
	size_t	lenght;
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(readed);
	lenght = ft_strlen(buffer) + ft_strlen(readed) + 1;
	jointed = ft_calloc(lenght, 1);
	if (jointed == NULL)
		return (NULL);
	while (readed[j] != '\0')
	{
		jointed[j] = readed[j];
		j++;
	}
	i = 0;
	while (buffer[i] != '\0')
		jointed[j++] = buffer[i++];
	jointed[j] = '\0';
	free(readed);
	return (jointed);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}
