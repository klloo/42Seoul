/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:30:43 by heeyjang          #+#    #+#             */
/*   Updated: 2023/04/03 13:23:52 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (!s)
	{
		if (write(fd, "(null)", 6) < 0)
			return (-1);
		len = 6;
	}
	else
	{
		while (*s)
		{
			if (write(fd, s++, 1) < 0)
				return (-1);
			len++;
		}
	}
	return (len);
}

int	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) < 0)
		return (-1);
	return (1);
}

int	ft_putnbr_fd(long long num, int n, char format, int fd)
{
	char	*num_str;
	int		len;
	char	*base;

	if (format == 'p')
		if (write(fd, "0x", 2) < 0)
			return (-1);
	base = ft_get_base(format);
	if (format == 'u' || format == 'x' || format == 'X' || format == 'p')
		num_str = ft_itoa_unsigned_base(num, n, base);
	else
		num_str = ft_itoa(num);
	if (!num_str)
		return (-1);
	len = ft_putstr_fd(num_str, 1);
	if (format == 'p')
		len += 2;
	free(num_str);
	return (len);
}

int	ft_print_format(char format, va_list va)
{
	int	len;

	len = 0;
	if (format == 's')
		len = ft_putstr_fd(va_arg(va, char *), 1);
	else if (format == 'd' || format == 'i')
		len = ft_putnbr_fd(va_arg(va, int), 10, format, 1);
	else if (format == 'u')
		len = ft_putnbr_fd(va_arg(va, unsigned int), 10, format, 1);
	else if (format == 'c')
		len = ft_putchar_fd(va_arg(va, int), 1);
	else if (format == 'x' || format == 'X')
		len = ft_putnbr_fd(va_arg(va, unsigned int), 16, format, 1);
	else if (format == 'p')
		len = ft_putnbr_fd(va_arg(va, size_t), 16, format, 1);
	else if (format == '%')
		len = ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	va;
	int		printed;
	int		len;

	printed = 0;
	va_start(va, format);
	while (*format)
	{
		len = 0;
		if (*format == '%')
		{
			format++;
			len = ft_print_format(*format, va);
		}
		else
			len = ft_putchar_fd(*format, 1);
		if (len < 0)
			return (-1);
		printed += len;
		format++;
	}
	va_end(va);
	return (printed);
}

// #include <stdio.h>
// #include <limits.h>
// int main()
// {
// // 	int a;
// // 	char *nullstr = 0;
// // 	unsigned int ui = 4294967295;
// // 	int len1 = ft_printf("str: %s %s c: %c i : %i x: %x X: %X p: %p u: %u\n"
// // 		, nullstr, "asdf", 97, 97, 12332, 12332, &a, ui);
// // 	int len2 = printf("str: %s %s c: %c i : %i x: %x X: %X p: %p u: %u\n"
// // 		, nullstr, "asdf", 97, 97, 12332, 12332, &a, ui);
// // 	int len3 = ft_printf("len1: %d len2: %d %%\n", len1, len2);
// // 	ft_printf("len2: %d\n", len3);
// 	ft_printf("ft long min: %p, long max: %p\n", LONG_MIN, LONG_MAX);
// 	printf("p long min: %p, long max: %p\n", LONG_MIN, LONG_MAX);
// 	ft_printf("ft ulong_max: %p, -ulong max: %p\n", ULONG_MAX, -ULONG_MAX);
// 	printf("p ulong_max: %p, -ulong max: %p\n", ULONG_MAX, -ULONG_MAX);
// }