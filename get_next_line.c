/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:17:16 by rpothier          #+#    #+#             */
/*   Updated: 2024/02/23 13:49:32 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	ssize_t		nbr_read;

	line = NULL;
	nbr_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	stash = fill_stash_w_read(fd, &stash, nbr_read);
	if (stash == NULL)
		return (NULL);
	line = fill_line(&stash, line);
	if (!line)
		return (free(stash), NULL);
	stash = clean_stash(&stash);
	if (!stash)
		return (free(line), NULL);
	return (line);
}

char	*fill_stash_w_read(int fd, char **stash, ssize_t nbr_read)
{
	char	*buf;

	while (found_n(*stash) == 0 && nbr_read != 0)
	{
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buf)
			return (NULL);
		nbr_read = read(fd, buf, BUFFER_SIZE);
		//buf[nbr_read] = '\0';
		/* if ((stash == NULL && nbr_read == 0) || nbr_read == -1)
		{
			free(buf);
			return (NULL);
		} */
		*stash = add_buf_to_stash(stash, buf, nbr_read);
		free(buf);
	}
	return (*stash);
}

char	*add_buf_to_stash(char **stash, char *buf, ssize_t nbr_read)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	j = 0;
	new_stash = ft_calloc(ft_strlen(*stash) + nbr_read + 1, sizeof(char));
	if (!new_stash)
		return (NULL);
	while (*stash && (*stash)[i])
	{
		new_stash[i] = (*stash)[i];
		i++;
	}
	while (buf && buf[j] && j < nbr_read)
	{
		new_stash[i] = buf[j];
		i++;
		j++;
	}
	//new_stash[i] = '\0';
	return (free(*stash), new_stash);
}

char	*fill_line(char **stash, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!*stash)
		return (NULL);
	line = ft_calloc(size_of_line(*stash) + 1, sizeof(char));
	if (!line)
		return (NULL);
	while ((*stash)[i])
	{
		if ((*stash)[i] == '\n')
		{
			line[j] = (*stash)[i];
			line[j + 1] = '\0';
			return (line);
		}
		line[j] = (*stash)[i];
		i++;
		j++;
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	return (line);
}

char	*clean_stash(char **stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*stash && (*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] && (*stash)[i] == '\n')
		i++;
	new_stash = ft_calloc(ft_strlen(*stash) - i + 1, sizeof(char));
	if (!new_stash)
		return (NULL);
	while (*stash && (*stash)[i])
	{
		new_stash[j] = (*stash)[i];
		i++;
		j++;
	}
	//new_stash[j] = '\0';
	free(*stash);
	return (new_stash);
}
