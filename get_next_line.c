/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:17:16 by rpothier          #+#    #+#             */
/*   Updated: 2024/02/06 15:35:31 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	void		*buf;
	static char	*stash;
	int			i;
	
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read(fd, buf, BUFFER_SIZE);
	stash = buf;
	
	while (stash[i] != '\n')
	{
		i++;
	}
}
