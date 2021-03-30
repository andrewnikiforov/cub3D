/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:42:54 by omillan           #+#    #+#             */
/*   Updated: 2021/03/30 11:34:25 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_flags				*make_flags(void)
{
	t_flags	*a;

	if (!(a = malloc(sizeof(t_flags))))
		return (0);
	a->c = 0;
	a->e = 0;
	a->f = 0;
	a->n = 0;
	a->s = 0;
	a->r = 0;
	a->so = 0;
	a->w = 0;
	a->m = 0;
	return (a);
}

t_plr				*make_plr(void)
{
	t_plr *a;

	if (!(a = malloc(sizeof(t_plr))))
		return (0);
	a->x = 0;
	a->y = 0;
	a->dir = 0;
	a->end = 0;
	a->start = 0;
	a->dir_x = 0;
	a->dir_y = 0;
	a->plan_x = 0;
	a->plan_y = 0;
	return (a);
}

t_lodev				*make_l(t_all *all, int i)
{
	t_lodev *l;

	if (!(l = malloc(sizeof(t_lodev))))
		return (0);
	l->cam_x = 2 * i / (double)(all->mlx_win->win_x) - 1;
	l->ray_d_x = all->plr->dir_x + all->plr->plan_x * l->cam_x;
	l->ray_dir_y = all->plr->dir_y + all->plr->plan_y * l->cam_x;
	l->map_x = (int)all->plr->x;
	l->map_y = (int)all->plr->y;
	l->del_dst_x = fabs(1 / l->ray_d_x);
	l->del_dst_y = fabs(1 / l->ray_dir_y);
	l->per_wal_dst = 0;
	l->step_x = 0;
	l->step_y = 0;
	l->hit = 0;
	l->side = 0;
	l->line_h = 0;
	l->drow_start = 0;
	l->drow_end = 0;
	l->wal_x = 0;
	l->text_x = 0;
	l->step = 0;
	l->text_y = 0;
	l->color = 0;
	return (l);
}

int					check_plr_out(char *l)
{
	int i;
	int j;

	i = -1;
	j = ft_strlen(l) - 1;
	while (l[++i] == ' ' && l[i])
		if (ft_isalpha(l[i]) != 0)
			return (-1);
	if (j >= 0)
	{
		while (l[--j] == ' ' && j >= 0)
			if (ft_isalpha(l[i]) != 0)
				return (-1);
	}
	return (0);
}

int					check_flags(t_all *all)
{
	if (all->f->c == 1 && all->f->e == 1 && all->f->f == 1 &&
			all->f->f == 1 && all->f->n == 1 && all->f->r == 1 &&
			all->f->s == 1 && all->f->so == 1 && all->f->w == 1)
	{
		all->f->m++;
		return (0);
	}
	return (-1);
}
