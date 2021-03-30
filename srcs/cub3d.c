/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:28:31 by omillan           #+#    #+#             */
/*   Updated: 2021/03/30 13:01:21 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				exit_all(t_all *all, int i)
{
	free(all->f);
	if (all->f_c_color)
		free(all->f_c_color);
	free(all->mlx_win->mlx);
	free(all->mlx_win->win);
	free(all->mlx_win);
	if (all->plr)
		free(all->plr);
	free_tex(all);
	if (all->map)
		num_str_free_arr(all->map, 2);
	if (all->img_data)
		free(all->img_data);
	if (i > 0)
		free_else(all);
	if (all->spr)
		free(all->spr);
	free(all);
	exit(0);
}

char				ft_ischr(char *s, char c)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			break ;
	return (s[i]);
}

void				plr_bihevior(t_all *all)
{
	int		x;
	int		y;

	y = -1;
	while (all->map[++y])
	{
		x = -1;
		while (all->map[y][++x])
		{
			if (ft_strchr("SWNE", all->map[y][x]))
			{
				all->plr->x = x + 0.5;
				all->plr->y = y + 0.5;
				if (ft_ischr("SWNE", all->map[y][x]) == 'S')
					if_s(all);
				if (ft_ischr("SWNE", all->map[y][x]) == 'W')
					if_w(all);
				if (ft_ischr("SWNE", all->map[y][x]) == 'N')
					if_n(all);
				if (ft_ischr("SWNE", all->map[y][x]) == 'E')
					if_e(all);
				all->map[y][x] = '0';
			}
		}
	}
}

void				normi(t_all *all)
{
	all->sprite = make_tex_to_img();
	plr_bihevior(all);
	all->mlx_win->win = mlx_new_window(all->mlx_win->mlx, all->mlx_win->win_x,
											all->mlx_win->win_y, "cub3D");
	if (all->sprite == 0)
		exit_all(all, 1);
	load_textures(all);
	all->img_data->img = mlx_new_image(all->mlx_win->mlx, all->mlx_win->win_x,
														all->mlx_win->win_y);
	all->img_data->addr = mlx_get_data_addr(all->img_data->img,
				&all->img_data->bits_per_pixel, &all->img_data->line_length,
													&all->img_data->endian);
}

int					main(int argc, char **argv)
{
	t_all	*all;

	if ((all = make_all()) == 0)
		exit_all(all, 0);
	all->mlx_win->mlx = mlx_init();
	if ((all->spr = make_sprite()) == 0)
		exit_all(all, 0);
	if ((all->map = check_map(argc, argv, all)) == 0)
		exit_all(all, 0);
	normi(all);
	if (argc == 3 && ft_strnstr(argv[2], "--save", 6) == 0 &&
												ft_strlen(argv[2]) == 6)
		return (save_bmp(all));
	if ((argc == 3 && ft_strnstr(argv[2], "--save", 6) == -1) ||
								(argc == 3 && ft_strlen(argv[2]) != 6))
		ft_return(7, all);
	mlx_hook(all->mlx_win->win, 2, 1L << 0, &key_hook, all);
	mlx_hook(all->mlx_win->win, 17, 0l, &krest, all);
	mlx_loop_hook(all->mlx_win->mlx, &put_map, all);
	mlx_loop(all->mlx_win->mlx);
	exit_all(all, 1);
}
