/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:07:52 by omillan           #+#    #+#             */
/*   Updated: 2021/03/08 17:02:26 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				sort_sprites(int *order, double *dist, int count)
{
	t_pair	*spr;
	int		i;

	i = -1;
	if (!(spr = (t_pair*)malloc(sizeof(t_pair) * count)))
		return ;
	while (++i < count)
	{
		spr[i].f = dist[i];
		spr[i].sec = order[i];
	}
	sort_order(spr, count);
	i = -1;
	while (++i < count)
	{
		dist[i] = spr[count - i - 1].f;
		order[i] = spr[count - i - 1].sec;
	}
	free(spr);
}

void				spr_palitr(t_all *all, t_draw_spr *dr)
{
	dr->inv = 1.0 / (all->plr->plan_x * all->plr->dir_y -
											all->plr->dir_x * all->plr->plan_y);
	dr->trans_x = dr->inv * (all->plr->dir_y * dr->spr_x -
												all->plr->dir_x * dr->spr_y);
	dr->trans_y = dr->inv * (-all->plr->plan_y * dr->spr_x +
											all->plr->plan_x * dr->spr_y);
	dr->spr_screen_x = (int)((all->mlx_win->win_x / 2) * (1 + dr->trans_x /
															dr->trans_y));
	dr->spr_height = (int)fabs(all->mlx_win->win_y / dr->trans_y);
	dr->drow_start_y = all->mlx_win->win_y / 2 - dr->spr_height / 2;
	if (dr->drow_start_y < 0)
		dr->drow_start_y = 0;
	dr->drow_end_y = dr->spr_height / 2 + all->mlx_win->win_y / 2;
	if (dr->drow_end_y >= all->mlx_win->win_y)
		dr->drow_end_y = all->mlx_win->win_y - 1;
	dr->spr_width = (int)fabs(all->mlx_win->win_y / dr->trans_y);
	dr->drow_start_x = dr->spr_screen_x - dr->spr_width / 2;
	if (dr->drow_start_x < 0)
		dr->drow_start_x = 0;
	dr->drow_end_x = dr->spr_width / 2 + dr->spr_screen_x;
	if (dr->drow_end_x >= all->mlx_win->win_x)
		dr->drow_end_x = all->mlx_win->win_x - 1;
}

void				spr_color(t_all *all, t_draw_spr *dr, int stripe, int y)
{
	dr->color = ((int *)all->sprite->addr)[all->sprite->width *
													dr->tex_y + dr->tex_x];
	if (dr->color != 0)
		my_mlx_pixel_put(all, stripe, y, dr->color);
}

void				art_spr(t_all *all, double buf[], t_tex_to_img *t,
														t_draw_spr *dr)
{
	int stripe;
	int y;
	int d;

	stripe = dr->drow_start_x;
	while (stripe < dr->drow_end_x)
	{
		y = dr->drow_start_y;
		dr->tex_x = (int)(256 * (stripe - (dr->spr_screen_x - dr->spr_width
									/ 2)) * t->width / dr->spr_width) / 256;
		if (dr->trans_y > 0 && stripe > 0 && stripe < all->mlx_win->win_x &&
												dr->trans_y < buf[stripe])
		{
			while (y < dr->drow_end_y)
			{
				d = y * 256 - all->mlx_win->win_y * 128 + dr->spr_height
																	* 128;
				dr->tex_y = d * t->higth / dr->spr_height / 256;
				spr_color(all, dr, stripe, y);
				y++;
			}
		}
		stripe++;
	}
}

void				drow_sprites(t_all *all, t_tex_to_img *t, double buf[])
{
	int				spr_order[all->spr->count];
	double			spr_dist[all->spr->count];
	t_sprite		s_pr[all->spr->count];
	t_draw_spr		*dr;

	dr = make_dr();
	sprite_array(s_pr, all, spr_order, spr_dist);
	sort_sprites(spr_order, spr_dist, all->spr->count);
	while (++dr->z < all->spr->count)
	{
		dr->spr_x = s_pr[spr_order[dr->z]].x - all->plr->x;
		dr->spr_y = s_pr[spr_order[dr->z]].y - all->plr->y;
		spr_palitr(all, dr);
		art_spr(all, buf, t, dr);
	}
	free(dr);
}
