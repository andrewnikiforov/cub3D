/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:32:56 by omillan           #+#    #+#             */
/*   Updated: 2021/03/25 16:30:11 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data_img			*make_img_data(void)
{
	t_data_img	*a;

	if (!(a = (t_data_img *)malloc(sizeof(t_data_img))))
		return (0);
	a->addr = 0;
	a->bits_per_pixel = 0;
	a->endian = 0;
	a->img = 0;
	a->line_length = 0;
	return (a);
}

void				my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char *dst;

	dst = all->img_data->addr + (y * all->img_data->line_length +
								x * (all->img_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int					put_map(t_all *all)
{
	ft_load_cub(all);
	mlx_put_image_to_window(all->mlx_win->mlx, all->mlx_win->win,
													all->img_data->img, 0, 0);
	return (0);
}
