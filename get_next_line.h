/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanalefernandez <ivanalefernandez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:03:52 by ivanalefern       #+#    #+#             */
/*   Updated: 2023/08/09 11:45:04 by ivanalefern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 18
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

char	*ft_strjoin(char *readed, char *buffer);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_calloc(size_t count, size_t size);
char	*clean_reader(char *readed);
size_t	ft_strlen(const char *s);
#endif