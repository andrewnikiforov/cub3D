/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_uyils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:21:02 by omillan           #+#    #+#             */
/*   Updated: 2021/03/08 16:23:02 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_draw_spr			*make_dr(void)
{
	t_draw_spr *a;

	if (!(a = malloc(sizeof(t_draw_spr))))
		return (0);
	a->color = 0;
	a->drow_end_x = 0;
	a->drow_end_y = 0;
	a->drow_start_x = 0;
	a->drow_start_y = 0;
	a->inv = 0;
	a->spr_height = 0;
	a->spr_screen_x = 0;
	a->spr_width = 0;
	a->spr_x = 0;
	a->spr_y = 0;
	a->tex_x = 0;
	a->tex_y = 0;
	a->trans_x = 0;
	a->trans_y = 0;
	a->z = -1;
	return (a);
}

t_sprite			*make_sprite(void)
{
	t_sprite	*a;

	if (!(a = malloc(sizeof(t_sprite))))
		return (0);
	a->count = 0;
	a->spr_tex = 0;
	a->x = 0;
	a->y = 0;
	return (a);
}

void				sort_order(t_pair *orders, int count)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < count - 1)
		{
			if (orders[j].f > orders[j + 1].f)
			{
				tmp.f = orders[j].f;
				tmp.sec = orders[j].sec;
				orders[j].f = orders[j + 1].f;
				orders[j].sec = orders[j + 1].sec;
				orders[j + 1].f = tmp.f;
				orders[j + 1].sec = tmp.sec;
			}
		}
	}
}

void				sprite_array(t_sprite s_pr[], t_all *all, int spr_order[],
															double spr_dist[])
{
	int i;
	int j;
	int k;

	k = -1;
	i = -1;
	while (all->map[++i])
	{
		j = -1;
		while (all->map[i][++j])
		{
			if (all->map[i][j] == '2')
			{
				s_pr[++k].x = j + 0.5;
				s_pr[k].y = i + 0.5;
			}
		}
	}
	j = -1;
	while (++j < all->spr->count)
	{
		spr_order[j] = j;
		spr_dist[j] = ((all->plr->x - s_pr[j].x) * (all->plr->x -
		s_pr[j].x) + (all->plr->y - s_pr[j].y) * (all->plr->y - s_pr[j].y));
	}
}
