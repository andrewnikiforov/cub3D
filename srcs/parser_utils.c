/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:30:49 by omillan           #+#    #+#             */
/*   Updated: 2021/03/30 14:18:02 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				x_size(t_all *all, char *l, char *s)
{
	all->conf_x = ft_atoi(l);
	all->conf_y = ft_atoi(s);
	if (ft_atoi(l) < 320)
	{
		all->conf_x = 320;
		all->mlx_win->win_x = 320;
	}
	if (ft_atoi(l) > all->mlx_win->x_max || ft_atoi(l) == -1)
		all->mlx_win->win_x = all->mlx_win->x_max;
	else
		all->mlx_win->win_x = ft_atoi(l);
	if (ft_atoi(s) < 240)
	{
		all->conf_y = 240;
		all->mlx_win->win_y = 240;
	}
	if (ft_atoi(s) > all->mlx_win->x_max || ft_atoi(s) == -1)
		all->mlx_win->win_y = all->mlx_win->y_max;
	else
		all->mlx_win->win_y = ft_atoi(s);
}

int					chek_minus(char **arr)
{
	int		k;

	k = -1;
	while (arr[++k])
	{
		if (arr[k] == NULL)
			return (-1);
		if (ft_atoi(arr[k]) < 0)
			return (-1);
		if (ft_atoi(arr[k]) > 255)
			return (-1);
		if (count_dig(arr[k]) > 3)
			return (-1);
		if (count_alph(arr[k]) > 0)
			return (-1);
		if (is_minus(arr[k]) > 0)
			return (-1);
	}
	return (0);
}

int					c_chek_minus(char **arr)
{
	int		k;

	k = -1;
	while (arr[++k])
	{
		if (arr[k] == NULL)
			return (-1);
		if (is_minus(arr[k]) > 0)
			return (-1);
		if (count_zpt(arr[k]) > 0)
			return (-1);
	}
	return (0);
}

int					get_r(char *line, t_all *all)
{
	char	**arr;

	mlx_get_screen_size(all->mlx_win->mlx, &all->mlx_win->x_max,
														&all->mlx_win->y_max);
	all->f->r++;
	arr = ft_split(line, ' ');
	if (num_str_free_arr(arr, 1) != 3 || c_chek_minus(arr) == -1
	|| count_alph(arr[1]) > 0 || count_alph(arr[2]) > 0 || ft_atoi(arr[1]) == 0
														|| ft_atoi(arr[2]) == 0)
	{
		num_str_free_arr(arr, 2);
		return (-1);
	}
	x_size(all, arr[1], arr[2]);
	num_str_free_arr(arr, 2);
	return (0);
}

int					get_f_c_color(char *line, t_all *all, char f_c)
{
	char	**arr;
	int		i;

	arr = ft_split(line, ',');
	if (chek_minus(arr) == -1 || num_str_free_arr(arr, 1) != 3 ||
							if_no_digit(arr) == 1 || count_zpt(line) != 2)
	{
		num_str_free_arr(arr, 2);
		return (-1);
	}
	i = create_trgb(0, ft_atoi(arr[0]), ft_atoi(arr[1]), ft_atoi(arr[2]));
	if (f_c == 'f')
	{
		all->f_c_color->f_color = i;
		all->f->f++;
	}
	else if (f_c == 'c')
	{
		all->f_c_color->c_color = i;
		all->f->c++;
	}
	num_str_free_arr(arr, 2);
	return (0);
}
