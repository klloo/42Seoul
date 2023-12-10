/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:22:09 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/27 17:29:07 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	put_no_file_error(char *file_name)
{
	write(2, "cat: ", 5);
	while (*file_name)
		write(2, file_name++, 1);
	write(2, ": No such file or directory", 27);
}

void	read_file(char *file_name)
{
	int		fd;
	int		n;
	char	buf[29];

	fd = open(file_name, O_RDONLY);
	n = 1;
	while (n != 0)
	{
		n = read(fd, buf, 29);
		if (n == -1)
		{
			put_no_file_error(file_name);
			break ;
		}
		write(1, buf, n);
	}
	close(fd);
}

void	read_std(void)
{
	int		n;
	char	buf[29];

	n = 1;
	while (n != 0)
	{
		n = read(0, buf, 29);
		if (n == -1)
			break ;
		write(1, buf, n);
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc >= 2)
	{
		while (i < argc)
		{
			read_file(argv[i]);
			i++;
		}
	}
	else
		read_std();
	return (0);
}
