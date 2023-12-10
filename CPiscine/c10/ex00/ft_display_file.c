/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:47:44 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/27 15:23:07 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	put_str(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		n;
	char	buf[1024];

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		n = 1;
		while (n != 0)
		{
			n = read(fd, buf, 1024);
			if (n == -1)
			{
				put_str("Cannot read file.\n");
				break ;
			}
			write(1, buf, n);
		}
		close(fd);
	}
	else if (argc == 1)
		put_str("File name missing.\n");
	else if (argc > 2)
		put_str("Too many arguments.\n");
	return (0);
}
