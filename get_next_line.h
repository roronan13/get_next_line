/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpothier <ronanpothier@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:18:15 by rpothier          #+#    #+#             */
/*   Updated: 2024/02/23 02:21:36 by ronanpothie      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*fill_stash_w_read(int fd, char *stash, ssize_t nbr_read);
char	*add_buf_to_stash(char *stash, char *buf, ssize_t nbr_read);
char	*fill_line(char *stash, char *line);
char	*clean_stash(char *stash);
int		found_n(char *stash);
size_t	size_of_line(char *stash);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif