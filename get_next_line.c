/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpothier <ronanpothier@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:17:16 by rpothier          #+#    #+#             */
/*   Updated: 2024/02/23 02:21:07 by ronanpothie      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	ssize_t		nbr_read;

	//stash = NULL;
	line = NULL;
	nbr_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	stash = fill_stash_w_read(fd, stash, nbr_read);
	if (stash == NULL)
		return (NULL);
	//printf("stash 2 : %s\n", stash);
	line = fill_line(stash, line);
	stash = clean_stash(stash);
	if (!line)
	{
		//free(stash);
		free(line);
		return (NULL);
	}
	return (line);
}

char	*fill_stash_w_read(int fd, char *stash, ssize_t nbr_read)
{
	char	*buf;

	//while (!found_n(stash) && nbr_read != 0)
	while (found_n(stash) == 0 && nbr_read != 0)
	{
		//printf("stash debut : %s\n", stash);
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		nbr_read = read(fd, buf, BUFFER_SIZE);
		buf[nbr_read] = '\0';
		//printf("buf : %s\n", buf);
		if ((stash == NULL && nbr_read == 0) || nbr_read == -1)
		{
			free(buf);
			return (NULL);
		}
		//printf("stash 1000 : %s\n", stash);
		stash = add_buf_to_stash(stash, buf, nbr_read);
		//printf("stash 1 : %s\n", stash);
		free(buf);
		//buf = NULL;
		//printf("stash 1 : %s\n", stash);
		//printf("buf 2 : %s\n", buf);
	}
	return (stash);
}

char	*add_buf_to_stash(char *stash, char *buf, ssize_t nbr_read)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	j = 0;
	//printf("stash --- : %s\n", stash);
	//printf("buf --- : %s\n", buf);
	// if (!stash)
	// {
	// 	new_stash = malloc(sizeof(char) * (nbr_read + 1));
	// 	*new_stash = *buf;
	// 	return (new_stash);
	// }
	//else
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) + nbr_read + 1));
	if (!new_stash)
		return (NULL);
	//printf("okok\n");
	while (stash && stash[i])
	{
		new_stash[i] = stash[i];
		i++;
	}
	//printf("okok2\n");
	while (buf && buf[j] && j < nbr_read)
	{
		new_stash[i] = buf[j];
		i++;
		j++;
	}
	new_stash[i] = '\0';
	//printf("new_stash : %s\n", new_stash);
	return (new_stash);
}

char	*fill_line(char *stash, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	line = malloc(sizeof(char) * (size_of_line(stash) + 1));
	if (!line)
		return (NULL);
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			line[j] = stash[i];
			//break ;
			line[j + 1] = '\0';
			return (line);
		}
		line[j] = stash[i];
		i++;
		j++;
	}
	//line[j] = '\0';
	//return (line);
	return (NULL);
}

char	*clean_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (stash && stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		i++;
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_stash)
		return (NULL);
	while (stash && stash[i])
	{
		new_stash[j] = stash[i];
		i++;
		j++;
	}
	new_stash[j] = '\0';
	free(stash);
	//stash = new_stash;
	return (new_stash);
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