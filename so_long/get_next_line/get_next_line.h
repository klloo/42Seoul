/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:39:05 by heeyjang          #+#    #+#             */
/*   Updated: 2023/12/08 16:39:06 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 42

char			*ft_strchr(char *s, int c);
unsigned int	ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_gnl_strjoin(char *pre, char *buf);
char			*ft_substr(char *s, unsigned int start, size_t len);
void			free_ptr(char **ptr);
char			*get_next_line(int fd);
#endif