/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:17:16 by rpothier          #+#    #+#             */
/*   Updated: 2024/02/14 14:19:00 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	void		*buf;
	static char	*stash;
	char		*line;
	int			i;
	
	i = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	stash = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read(fd, buf, BUFFER_SIZE);
	stash = buf;
	
	while (stash[i])
	{
		if (stash[i] != '\n')
			i++;
		else
		{
			line = malloc(sizeof(char) * (i + 1));
			ft_strlcat(line, stash, i + 1);
		}
	}
}
