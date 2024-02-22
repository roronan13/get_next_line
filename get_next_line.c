 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:17:16 by rpothier          #+#    #+#             */
/*   Updated: 2024/02/16 17:06:33 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	ssize_t		nbr_read;

	stash = NULL;
	line = NULL;
	nbr_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	read_and_fill_stash(fd, stash, nbr_read);
	if (stash == NULL)
		return (NULL);
	fill_line(stash, line);
	clean_stash(stash);
	if (!line)
	{
		free(stash);
		free(line);
		return (NULL);
	}
	return (line);
}

void	read_and_fill_stash(int fd, char *stash, ssize_t nbr_read)
{
	char	*buf;

	while (!found_n(stash) && nbr_read != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		nbr_read = read(fd, buf, BUFFER_SIZE);
		if ((stash == NULL && nbr_read == 0) || nbr_read == -1)
		{
			free(buf);
			return ;
		}
		buf[nbr_read] = '\0';
		add_buf_to_stash(stash, buf, nbr_read);
		free(buf);
	}
}

void	add_buf_to_stash(char *stash, char *buf, ssize_t nbr_read)
{
	stash = ft_strjoin(stash, buf);
	if (!stash)
		return ;
}

void	fill_line(char *stash, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!stash)
		return ;
	size_of_line(line, stash);
	if (!line)
		return ;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			line[j] = stash[i];
			break ;
		}
		line[j] = stash[i];
		i++;
		j++;
	}
	line[j + 1] = '\0';
}

void	clean_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		i++;
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_stash)
		return ;
	while (stash[i])
	{
		new_stash[j] = stash[i];
		i++;
		j++;
	}
	new_stash[j] = '\0';
	free(stash);
	stash = new_stash;
}


////////////////////////////////////////////


/* char	*get_next_line(int fd)
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
				ft_strlcat(stash, &buf[nbr_read - i], i + 2);
				line = stash;
				i = 0;
				break ;
			}
			i++;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	char		*line;
	size_t		nbr_read;
	int			i;

	line = NULL;
	i = 0;
	while (line == NULL)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		nbr_read = read(fd, buf, BUFFER_SIZE);
		if (nbr_read == 0)
			return (NULL);
		buf[nbr_read] = '\0';
		stash = malloc(sizeof(char) * (nbr_read + 1));
		stash = ft_strdup(buf);
		while (stash[i])
		{
			if (stash[i] == '\n')
			{
				line = ft_memcpy(line, stash, i);
				
			}
			i++;
		}
		
	}
}
 */