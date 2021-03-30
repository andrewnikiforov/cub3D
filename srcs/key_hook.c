/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:59:01 by omillan           #+#    #+#             */
/*   Updated: 2021/03/26 21:12:07 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					krest(t_all *all)
{
	exit_all(all, 1);
	return (0);
}

void				turn_left_right(t_all *all, double corner)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = all->plr->dir_x;
	old_plane_x = all->plr->plan_x;
	all->plr->dir_x = all->plr->dir_x * cos(corner) - all->plr->dir_y *
																sin(corner);
	all->plr->dir_y = old_dir_x * sin(corner) + all->plr->dir_y * cos(corner);
	all->plr->plan_x = all->plr->plan_x * cos(corner) - all->plr->plan_y *
																sin(corner);
	all->plr->plan_y = old_plane_x * sin(corner) + all->plr->plan_y *
																cos(corner);
}

void				move_back_left(t_all *all, char c)
{
	if (c == 'b')
	{
		if (all->map[(int)all->plr->y]
						[(int)(all->plr->x - all->plr->dir_x * MOVE)] == '0')
			all->plr->x -= all->plr->dir_x * MOVE;
		if (all->map[(int)(all->plr->y - all->plr->dir_y * MOVE)]
													[(int)all->plr->x] == '0')
			all->plr->y -= all->plr->dir_y * MOVE;
	}
	if (c == 'l')
	{
		if (all->map[(int)all->plr->y]
						[(int)(all->plr->x - all->plr->plan_x * MOVE)] == '0')
			all->plr->x -= all->plr->plan_x * MOVE;
		if (all->map[(int)(all->plr->y - all->plr->plan_y * MOVE)]
													[(int)all->plr->x] == '0')
			all->plr->y -= all->plr->plan_y * MOVE;
	}
}

void				move_front_right(t_all *all, char c)
{
	if (c == 'f')
	{
		if (all->map[(int)all->plr->y]
						[(int)(all->plr->x + all->plr->dir_x * MOVE)] == '0')
			all->plr->x += all->plr->dir_x * MOVE;
		if (all->map[(int)(all->plr->y + all->plr->dir_y * MOVE)]
												[(int)all->plr->x] == '0')
			all->plr->y += all->plr->dir_y * MOVE;
	}
	if (c == 'r')
	{
		if (all->map[(int)all->plr->y]
						[(int)(all->plr->x + all->plr->plan_x * MOVE)] == '0')
			all->plr->x += all->plr->plan_x * MOVE;
		if (all->map[(int)(all->plr->y + all->plr->plan_y * MOVE)]
													[(int)all->plr->x] == '0')
			all->plr->y += all->plr->plan_y * MOVE;
	}
}

int					key_hook(int keycode, t_all *all)
{
	if (keycode == 53)
		exit_all(all, 1);
	if (keycode == 123)
		turn_left_right(all, -MOVE);
	if (keycode == 124)
		turn_left_right(all, MOVE);
	if (keycode == 13)
		move_front_right(all, 'f');
	if (keycode == 1)
		move_back_left(all, 'b');
	if (keycode == 0)
		move_back_left(all, 'l');
	if (keycode == 2)
		move_front_right(all, 'r');
	return (0);
}
