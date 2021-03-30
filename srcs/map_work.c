/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:34:30 by omillan           #+#    #+#             */
/*   Updated: 2021/03/26 16:59:39 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					count_point(char *s)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (s[++i])
		if (s[i] == '.')
			count++;
	return (count);
}

void				get_path_help(char **arr, t_all *all, char c)
{
	if (c == 'E')
	{
		all->text->ea_path = ft_strdup(arr[1]);
		all->f->e++;
	}
	if (c == 'S')
	{
		all->text->so_path = ft_strdup(arr[1]);
		all->f->so++;
	}
	if (c == 's')
	{
		all->text->sprite = ft_strdup(arr[1]);
		all->f->s++;
	}
	if (c == 'N')
	{
		all->text->no_path = ft_strdup(arr[1]);
		all->f->n++;
	}
	if (c == 'W')
	{
		all->text->we_path = ft_strdup(arr[1]);
		all->f->w++;
	}
}

int					get_path(char *line, t_all *all, char c)
{
	char	**arr;

	arr = ft_split(line, ' ');
	if (num_str_free_arr(arr, 1) > 2 || check_file(arr[1]) == -1)
	{
		num_str_free_arr(arr, 2);
		return (-1);
	}
	if (c == 'N')
		get_path_help(arr, all, 'N');
	if (c == 'W')
		get_path_help(arr, all, 'W');
	if (c == 'E')
		get_path_help(arr, all, 'E');
	if (c == 'S')
		get_path_help(arr, all, 'S');
	if (c == 's')
		get_path_help(arr, all, 's');
	num_str_free_arr(arr, 2);
	return (0);
}

int					map_elements(char *s, t_all *all, int tr)
{
	int		i;

	if (*s == 'R' && *(s + 1) == ' ' && all->f->r == 0)
		i = get_r(s, all);
	else if (*s == 'F' && *(s + 1) == ' ' && all->f->f == 0)
		i = get_f_c_color(s + 1, all, 'f');
	else if (*s == 'C' && *(s + 1) == ' ' && all->f->c == 0)
		i = get_f_c_color(s + 1, all, 'c');
	else if (*s == 'N' && *(s + 1) == 'O' && *(s + 2) == ' ' && all->f->n == 0)
		i = get_path(s, all, 'N');
	else if (*s == 'W' && *(s + 1) == 'E' && *(s + 2) == ' ' && all->f->w == 0)
		i = get_path(s, all, 'W');
	else if (*s == 'E' && *(s + 1) == 'A' && *(s + 2) == ' ' && all->f->e == 0)
		i = get_path(s, all, 'E');
	else if (*s == 'S' && *(s + 1) == 'O' && *(s + 2) == ' ' && all->f->so == 0)
		i = get_path(s, all, 'S');
	else if (*s == 'S' && *(s + 1) == ' ' && all->f->s == 0)
		i = get_path(s, all, 's');
	else
	{
		free(s - tr);
		return (-1);
	}
	free(s - tr);
	return (i == -1) ? (-1) : (0);
}
