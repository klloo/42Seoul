/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:34:35 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/12 21:11:58 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
int		ft_atoll(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_is_number(char *ft_putstr);
int		ft_is_out_of_int(char *str);

int	main(int argc, char *argv[])
{
	int			x;
	int			y;

	if (argc != 3)
	{
		ft_putstr("require two parameters.\n");
		return (0);
	}
	if (ft_is_number(argv[1]) == 0 || ft_is_number(argv[2]) == 0)
	{
		ft_putstr("require integer.\n");
		return (0);
	}
	if (ft_is_out_of_int(argv[1]) == 0 || ft_is_out_of_int(argv[2]) == 0)
	{
		ft_putstr("out of integer range.\n");
		return (0);
	}
	x = (int) ft_atoll(argv[1]);
	y = (int) ft_atoll(argv[2]);
	rush(x, y);
}
