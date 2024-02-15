/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:17:16 by rpothier          #+#    #+#             */
/*   Updated: 2024/02/15 22:04:00 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	char		*line;
	int			i;
	ssize_t		nbr_read;

	i = 0;
	line = NULL;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	stash = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	nbr_read = read(fd, buf, BUFFER_SIZE);
	if (nbr_read == 0)
		return (NULL);
	buf[nbr_read] = '\0';
	stash = ft_strdup(buf);
/* 	printf("%s\n", buf);
	printf("%s\n", stash); */

	while (line == NULL)
	{
		nbr_read = read(fd, buf, BUFFER_SIZE);
		if (nbr_read == 0)
			return (NULL);
		buf[nbr_read] = '\0';
		while (buf[i])
		{
			if (buf[i] == '\0')
			{
				stash = ft_strdup(buf);
				free(buf);
				nbr_read = read(fd, buf, BUFFER_SIZE);
				stash = ft_strjoin(stash, buf);
				i = 0;
			}
			if (buf[i] == '\n')
			{
				line = malloc(sizeof(char) * (i + 2));
				ft_strlcat(stash, buf, i + 2);
				line = stash;
				break ;
			}
			i++;
		}
	}
	return (line);
}

/* 	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		nbr_read = read(fd, buf, BUFFER_SIZE);
		stash = ft_strjoin(stash, buf);
		printf("stash : %s\n", stash);
	}
	else
	{
		line = malloc(sizeof(char) * (i + 2));
		ft_strlcat(line, stash, i + 2);
		return (line);
	}
 */