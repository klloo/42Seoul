/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:53:55 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/26 17:09:33 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	calculate(int num1, int num2, char op);

int	ft_atoi(char *str);

void	print_nbr(int num)
{
	char	c;

	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (num == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
	if (num / 10 == 0)
	{
		c = num + '0';
		write(1, &c, 1);
		return ;
	}
	print_nbr(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
}

void	put_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	main(int argc, char *argv[])
{
	int		num1;
	int		num2;
	char	op;

	if (argc != 4)
		return (0);
	op = argv[2][0];
	if (str_len(argv[2]) != 1)
		op = '0';
	num1 = ft_atoi(argv[1]);
	num2 = ft_atoi(argv[3]);
	if (op == '/' && num2 == 0)
	{
		put_str("Stop : division by zero\n");
		return (0);
	}
	if (op == '%' && num2 == 0)
	{
		put_str("Stop : modulo by zero\n");
		return (0);
	}
	print_nbr(calculate(num1, num2, op));
	write(1, "\n", 1);
}
