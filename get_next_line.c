/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:17:16 by rpothier          #+#    #+#             */
/*   Updated: 2024/02/15 16:08:45 by rpothier         ###   ########.fr       */
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
	int			x;
	
	i = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	stash = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	nbr_read = read(fd, buf, BUFFER_SIZE);
	if (nbr_read == 0)
		return (NULL);
	buf[nbr_read] = '\0';
	printf("%ld\n", nbr_read);
	stash = buf;
	
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		nbr_read = read(fd, buf, BUFFER_SIZE);
		ft_strjoin(stash, buf);
	}
	else
	{
		line = malloc(sizeof(char) * (i + 2));
		ft_strlcat(line, stash, i + 2);
		return (line);
	}
}
