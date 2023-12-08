/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:37:32 by heeyjang          #+#    #+#             */
/*   Updated: 2023/12/08 16:41:06 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_message_error(void)
{
	perror("Error");
	exit(1);
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(s1);
	dest = (char *)malloc(src_len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i <= src_len)
	{
		dest[i] = s1[i];
		i++;
	}
	return (dest);
}

char	**get_map(char *fmap)
{
	char	*line;
	char	*all_lines;
	int		fd;

	line = "";
	all_lines = ft_strdup("");
	fd = open(fmap, O_RDONLY);
	if (fd < 0)
		ft_message_error();
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
	}
	free(line);
	close(fd);
	if (all_lines[0] == '\0')
		ft_message_error();
	return (ft_split(all_lines, '\n'));
}
