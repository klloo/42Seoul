/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:37:43 by heeyjang          #+#    #+#             */
/*   Updated: 2023/12/08 16:38:32 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_text(t_vars ***v)
{
	int		img_w;
	int		img_h;
	char	*text;
	char	*number;

	number = ft_itoa(++(**v)->movement);
	text = ft_strjoin("Move: ", number);
	(**v)->img = mlx_xpm_file_to_image(
			(**v)->mlx, "./img/wall.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(**v)->mlx, (**v)->win, (**v)->img, 0, 0);
	mlx_put_image_to_window(
		(**v)->mlx, (**v)->win, (**v)->img, 50, 0);
	mlx_put_image_to_window(
		(**v)->mlx, (**v)->win, (**v)->img, 50 * 2, 0);
	mlx_string_put((**v)->mlx, (**v)->win, 5, 10, 0xfffffff, text);
	printf("%s\n", number);
	free(text);
	free(number);
}
