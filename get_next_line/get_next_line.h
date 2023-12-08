/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:48:05 by heeyjang          #+#    #+#             */
/*   Updated: 2023/04/21 14:45:33 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FT_OPEN_MAX 49152
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char			*ft_strchr(char *s, int c);
unsigned int	ft_strlen(char *str);
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
char			*ft_strjoin(char *pre, char *buf);
char			*ft_substr(char *s, unsigned int start, size_t len);
void			free_ptr(char **ptr);
char			*get_next_line(int fd);
#endif
