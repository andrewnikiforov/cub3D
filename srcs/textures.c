/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:36:07 by omillan           #+#    #+#             */
/*   Updated: 2021/03/21 15:36:08 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				get_addr_news_text(t_all *all)
{
	all->n->addr = mlx_get_data_addr(all->n->img, &all->n->bits_per_pixel,
										&all->n->line_length, &all->n->endian);
	all->s->addr = mlx_get_data_addr(all->s->img, &all->s->bits_per_pixel,
										&all->s->line_length, &all->s->endian);
	all->w->addr = mlx_get_data_addr(all->w->img, &all->w->bits_per_pixel,
										&all->w->line_length, &all->w->endian);
	all->e->addr = mlx_get_data_addr(all->e->img, &all->e->bits_per_pixel,
										&all->e->line_length, &all->e->endian);
	all->sprite->addr = mlx_get_data_addr(all->sprite->img,
						&all->sprite->bits_per_pixel, &all->sprite->line_length,
														&all->sprite->endian);
}

void				load_textures(t_all *all)
{
	all->n = make_tex_to_img();
	all->s = make_tex_to_img();
	all->w = make_tex_to_img();
	all->e = make_tex_to_img();
	all->n->img = mlx_xpm_file_to_image(all->mlx_win->mlx, all->text->no_path,
												&all->n->width, &all->n->higth);
	all->s->img = mlx_xpm_file_to_image(all->mlx_win->mlx, all->text->so_path,
												&all->s->width, &all->s->higth);
	all->w->img = mlx_xpm_file_to_image(all->mlx_win->mlx, all->text->we_path,
												&all->w->width, &all->w->higth);
	all->e->img = mlx_xpm_file_to_image(all->mlx_win->mlx, all->text->ea_path,
												&all->e->width, &all->e->higth);
	all->sprite->img = mlx_xpm_file_to_image(all->mlx_win->mlx,
				all->text->sprite, &all->sprite->width, &all->sprite->higth);
	if (all->n->img == 0 || all->e->img == 0 || all->w->img == 0 ||
								all->s->img == 0 || all->sprite->img == 0)
	{
		put_error(8);
		exit_all(all, 1);
	}
	get_addr_news_text(all);
}

void				if_s(t_all *all)
{
	all->plr->dir_x = 0;
	all->plr->dir_y = 1;
	all->plr->plan_x = -0.66;
	all->plr->plan_y = 0;
}

void				if_w(t_all *all)
{
	all->plr->dir_x = -1;
	all->plr->dir_y = 0;
	all->plr->plan_x = 0;
	all->plr->plan_y = -0.66;
}

void				if_n(t_all *all)
{
	all->plr->dir_x = 0;
	all->plr->dir_y = -1;
	all->plr->plan_x = 0.66;
	all->plr->plan_y = 0;
}
