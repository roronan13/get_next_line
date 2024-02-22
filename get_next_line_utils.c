/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:22:13 by rpothier          #+#    #+#             */
/*   Updated: 2024/02/22 03:50:06 by rpothier         ###   ########.fr       */
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

void	size_of_line(char *line, char *stash)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			len++;
			break ;
		}
		len++;
		i++;
	}
	line = malloc(sizeof(char) * (len +1));
}

size_t ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t				i;
	long unsigned int	j;
	size_t				initial_dst_size;

	i = 0;
	j = 0;
	initial_dst_size = ft_strlen(dst);
	if (initial_dst_size > size)
		return (size + ft_strlen(src));
	if (size != 0)
	{
		while (dst[i])
			i++;
		while (src[j] && i < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src) + initial_dst_size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	size_s1;
	size_t	size_s2;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, size_s1 + 1);
	ft_strlcat(ptr, s2, size_s1 + size_s2 + 1);
	return (ptr);
}

/* char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	a;

	a = ft_strlen(s);
	ptr = malloc(sizeof(char) * a + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, a + 1);
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptr_dest;
	char	*ptr_src;

	i = 0;
	ptr_dest = (char *)dest;
	ptr_src = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (ptr_dest);
} */
