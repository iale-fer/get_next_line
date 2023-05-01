/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanalefernandez <ivanalefernandez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:03:07 by ivanalefern       #+#    #+#             */
/*   Updated: 2023/04/24 12:45:03 by ivanalefern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_reader(char *readed)
{
	int i;
	int x;
	int *tmp;

	i = 0;
	while(readed[i] != '\n')
	{
		i++;
	}
	if(!readed[i])
	{
		free(readed);
		return(NULL);
	}
}

static char	*cpy_line(char *readed)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!readed[0])
		return (NULL);
	while (readed[i] && readed[i] != '\n')
		i++;
	if (ft_strchr(readed, '\n'))
		line = ft_calloc(i + 2, 1);
	else
		line = ft_calloc(i + 1, 1);
	if (line == NULL)
		return (NULL);
	while (j <= i)
	{
		line[j] = readed[j];
		j++;
	}
	if (!line[0])
		return (free(line), NULL);
	return (line);
}

char	*read_buffer(int fd, char *readed)
{
	int		len;
	char	*buffer_temp;

	if (readed && (ft_strchr(readed, '\n')))
		return (readed);
	if (!readed)
		readed = ft_calloc (1, sizeof(char));
	buffer_temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer_temp == NULL)
		return (NULL);
	len = 1;
	while ((len > 0) && !(ft_strchr(buffer_temp, '\n')))
	{
		len = read(fd, buffer_temp, BUFFER_SIZE);
		if (len < 0)
			return (free(buffer_temp), free(readed), NULL);
		buffer_temp[len] = '\0';
		readed = ft_strjoin(readed, buffer_temp);
	}
	free(buffer_temp);
	return (readed);
}

char	*get_next_line(int fd)
{
	static char		*readed;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	readed = read_buffer(fd, readed);
	if (!readed)
	{	
		free(readed);
		return (NULL);
	}
	line = cpy_line(readed);
	readed = clean_reader(readed);
	return (line);
}