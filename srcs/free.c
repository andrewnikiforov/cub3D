/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:30:09 by omillan           #+#    #+#             */
/*   Updated: 2021/03/21 15:37:01 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				free_tex(t_all *all)
{
	if (all->text->no_path)
		free(all->text->no_path);
	if (all->text->sprite)
		free(all->text->so_path);
	if (all->text->we_path)
		free(all->text->we_path);
	if (all->text->ea_path)
		free(all->text->ea_path);
	if (all->text->sprite)
		free(all->text->sprite);
	if (all->text)
		free(all->text);
}

void				free_else(t_all *all)
{
	if (all->e->img)
		free(all->e->img);
	if (all->e)
		free(all->e);
	if (all->w->img)
		free(all->w->img);
	if (all->w)
		free(all->w);
	if (all->n->img)
		free(all->n->img);
	if (all->n)
		free(all->n);
	if (all->s->img)
		free(all->s->img);
	if (all->s)
		free(all->s);
	if (all->sprite->img)
		free(all->sprite->img);
	if (all->sprite)
		free(all->sprite);
}

int					num_str_free_arr(char **ar, int k)
{
	int i;

	i = 0;
	if (k == 1)
	{
		while (ar[i])
			i++;
		return (i);
	}
	if (k == 2)
	{
		while (ar[i])
		{
			free(ar[i]);
			i++;
		}
		free(ar);
	}
	return (0);
}
