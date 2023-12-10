/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:53:49 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/23 22:06:10 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	add(int a, int b);

int	sub(int a, int b);

int	mult(int a, int b);

int	div(int a, int b);

int	mod(int a, int b);

int	ft_is_space(char c)
{
	if (c == 32 || (9 <= c && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int			i;
	long long	result;
	int			sign;

	sign = 1;
	i = 0;
	while (ft_is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		result = result * 10;
		result = result + (str[i] - '0');
		i++;
	}
	result = result * sign;
	return ((int)result);
}

int	calculate(int num1, int num2, char op)
{
	int	(*funcp[5])(int, int);
	int	(*op_func)(int, int);

	funcp[0] = &add;
	funcp[1] = &sub;
	funcp[2] = &mult;
	funcp[3] = &div;
	funcp[4] = &mod;
	if (op == '+')
		op_func = funcp[0];
	else if (op == '-')
		op_func = funcp[1];
	else if (op == '*')
		op_func = funcp[2];
	else if (op == '/')
		op_func = funcp[3];
	else if (op == '%')
		op_func = funcp[4];
	else
		return (0);
	return (op_func(num1, num2));
}
