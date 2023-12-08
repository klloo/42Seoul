/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:44:39 by heeyjang          #+#    #+#             */
/*   Updated: 2023/04/02 14:50:28 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_get_unsinged_len(size_t num, int base);
int		ft_get_num_len(int num);
int		ft_abs(int n);
char	*ft_get_base(char format);
char	*ft_itoa(int num);
char	*ft_itoa_unsigned_base(size_t num, int n, char *base);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(long long num, int n, char format, int fd);
int		ft_print_format(char format, va_list va);
int		ft_printf(const char *format, ...);
#endif
