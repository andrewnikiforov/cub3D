/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:28:07 by omillan           #+#    #+#             */
/*   Updated: 2021/03/30 12:12:55 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				dir_n_step(t_all *all)
{
	if (all->l->ray_d_x < 0)
	{
		all->l->step_x = -1;
		all->l->side_dst_x = (all->plr->x - all->l->map_x) * all->l->del_dst_x;
	}
	else
	{
		all->l->step_x = 1;
		all->l->side_dst_x = (all->l->map_x + 1.0 - all->plr->x)
															* all->l->del_dst_x;
	}
	if (all->l->ray_dir_y < 0)
	{
		all->l->step_y = -1;
		all->l->side_dst_y = (all->plr->y - all->l->map_y) * all->l->del_dst_y;
	}
	else
	{
		all->l->step_y = 1;
		all->l->side_dst_y = (all->l->map_y + 1.0 - all->plr->y) *
															all->l->del_dst_y;
	}
}

void				hit(t_all *all)
{
	while (all->l->hit == 0)
	{
		if (all->l->side_dst_x < all->l->side_dst_y)
		{
			all->l->side_dst_x += all->l->del_dst_x;
			all->l->map_x += all->l->step_x;
			all->l->side = 0;
		}
		else
		{
			all->l->side_dst_y += all->l->del_dst_y;
			all->l->map_y += all->l->step_y;
			all->l->side = 1;
		}
		if (all->map[all->l->map_y][all->l->map_x] == '1')
			all->l->hit = 1;
	}
	if (all->l->side == 0)
		all->l->per_wal_dst = (all->l->map_x - all->plr->x +
									(1 - all->l->step_x) / 2) / all->l->ray_d_x;
	else
		all->l->per_wal_dst = (all->l->map_y - all->plr->y +
								(1 - all->l->step_y) / 2) / all->l->ray_dir_y;
	all->l->line_h = (int)(all->mlx_win->win_y / all->l->per_wal_dst);
	all->l->drow_start = all->mlx_win->win_y / 2 - all->l->line_h / 2;
}

t_tex_to_img		*ft_tex_x(t_all *all, t_tex_to_img *t)
{
	if (all->l->drow_start < 0)
		all->l->drow_start = 0;
	all->l->drow_end = all->mlx_win->win_y / 2 + all->l->line_h / 2;
	if (all->l->drow_end >= all->mlx_win->win_y)
		all->l->drow_end = all->mlx_win->win_y - 1;
	if (all->l->side == 0)
		all->l->wal_x = all->plr->y + all->l->per_wal_dst * all->l->ray_dir_y;
	else
		all->l->wal_x = all->plr->x + all->l->per_wal_dst * all->l->ray_d_x;
	all->l->wal_x -= floor(all->l->wal_x);
	if (all->l->side == 0 && all->l->step_x < 0)
		t = all->w;
	if (all->l->side == 0 && all->l->step_x > 0)
		t = all->e;
	if (all->l->side == 1 && all->l->step_y < 0)
		t = all->n;
	if (all->l->side == 1 && all->l->step_y > 0)
		t = all->s;
	all->l->text_x = (int)(all->l->wal_x * (double)t->width);
	if (all->l->side == 0 && all->l->ray_d_x > 0)
		all->l->text_x = t->width - all->l->text_x - 1;
	if (all->l->side == 1 && all->l->ray_dir_y < 0)
		all->l->text_x = t->width - all->l->text_x - 1;
	return (t);
}

void				drow_line(t_all *all, t_tex_to_img *t, int i)
{
	int y;

	y = -1;
	all->l->step = 1.0 * t->higth / all->l->line_h;
	all->l->text_pos = (all->l->drow_start - all->mlx_win->win_y / 2 +
											all->l->line_h / 2) * all->l->step;
	while (++y < all->mlx_win->win_y)
	{
		if (y <= all->l->drow_start)
			my_mlx_pixel_put(all, i, y, all->f_c_color->c_color);
		if (y > all->l->drow_start && y < all->l->drow_end)
		{
			all->l->text_y = (int)all->l->text_pos & (t->higth - 1);
			all->l->text_pos += all->l->step;
			all->l->color = ((int *)(t->addr))[t->higth *
											all->l->text_y + all->l->text_x];
			my_mlx_pixel_put(all, i, y, all->l->color);
		}
		if (y >= all->l->drow_end)
			my_mlx_pixel_put(all, i, y, all->f_c_color->f_color);
	}
}

void				ft_load_cub(t_all *all)
{
	int				i;
	t_tex_to_img	*t;
	double			buf[all->mlx_win->win_x];

	t = 0;
	i = -1;
	while (++i < all->mlx_win->win_x)
	{
		if ((all->l = make_l(all, i)) == 0)
		{
			free(all->l);
			exit_all(all, 1);
		}
		dir_n_step(all);
		hit(all);
		buf[i] = all->l->per_wal_dst;
		t = ft_tex_x(all, t);
		drow_line(all, t, i);
		free(all->l);
	}
	drow_sprites(all, t, buf);
}
