/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:22:13 by rpothier          #+#    #+#             */
/*   Updated: 2024/02/23 15:21:42 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_n(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	size_of_line(char *stash)
{
	size_t	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			break ;
		i++;
	}
	return (i + 1);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	max;
	size_t	i;

	max = (size_t)-1;
	if (size != 0 && nmemb > (max / size))
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	max = nmemb * size;
	i = 0;
	while (i < max)
		ptr[i++] = '\0';
	return (ptr);
}
