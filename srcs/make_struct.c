/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:30:26 by omillan           #+#    #+#             */
/*   Updated: 2021/03/25 16:03:54 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_f_c_colors		*make_f_c_color(void)
{
	t_f_c_colors *a;

	if (!(a = (t_f_c_colors *)malloc(sizeof(t_f_c_colors))))
		return (0);
	a->c_color = 0;
	a->f_color = 0;
	return (a);
}

t_mlx_win			*make_mlx_win(void)
{
	t_mlx_win *a;

	if (!(a = (t_mlx_win *)malloc(sizeof(t_mlx_win))))
		return (0);
	a->mlx = 0;
	a->win = 0;
	a->win_x = 0;
	a->win_y = 0;
	a->x_max = 0;
	a->y_max = 0;
	a->bmp_x = 0;
	a->bmp_y = 0;
	return (a);
}

t_textures			*make_text(void)
{
	t_textures *a;

	if (!(a = (t_textures *)malloc(sizeof(t_textures))))
		return (0);
	a->ea_path = 0;
	a->no_path = 0;
	a->so_path = 0;
	a->we_path = 0;
	a->sprite = 0;
	return (a);
}

t_tex_to_img		*make_tex_to_img(void)
{
	t_tex_to_img *a;

	if (!(a = malloc(sizeof(t_tex_to_img))))
		return (0);
	a->addr = 0;
	a->bits_per_pixel = 0;
	a->endian = 0;
	a->higth = 0;
	a->img = 0;
	a->line_length = 0;
	a->width = 0;
	return (a);
}

t_all				*make_all(void)
{
	t_all *a;

	if (!(a = (t_all *)malloc(sizeof(t_all))))
		return (0);
	a->text = make_text();
	a->mlx_win = make_mlx_win();
	a->f = make_flags();
	a->plr = make_plr();
	a->map = 0;
	a->f_c_color = make_f_c_color();
	a->img_data = make_img_data();
	a->conf_x = 0;
	a->conf_y = 0;
	return (a);
}
