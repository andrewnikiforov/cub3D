/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:24:32 by omillan           #+#    #+#             */
/*   Updated: 2021/03/26 14:00:57 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		write_pix(t_all *all, int fd)
{
	int				i;
	int				j;
	unsigned char	buf[4];

	i = all->mlx_win->win_x * (all->mlx_win->win_y - 1);
	while (i >= 0)
	{
		j = 0;
		while (j < all->mlx_win->win_x)
		{
			buf[0] = (((int *)(all->img_data->addr))[i] % 256);
			buf[1] = (((int *)(all->img_data->addr))[i] / 256 %
																	256);
			buf[2] = (((int *)(all->img_data->addr))[i] / 256 /
																256 % 256);
			buf[3] = 0;
			write(fd, buf, 4);
			i++;
			j++;
		}
		i -= 2 * all->mlx_win->win_x;
	}
}

void		set_buffer(t_all *all, char *buffer, int fd)
{
	int n;

	buffer[0] = '(';
	n = all->mlx_win->win_x;
	int_to_char(n, buffer + 4);
	n = all->mlx_win->win_y;
	int_to_char(n, buffer + 8);
	buffer[12] = 1;
	buffer[14] = ' ';
	write(fd, buffer, 40);
}

void		image(t_all *all, int fd)
{
	all->img_data->img = mlx_new_image(all->mlx_win->mlx, all->mlx_win->win_x,
														all->mlx_win->win_y);
	all->img_data->addr = mlx_get_data_addr(all->img_data->img,
				&all->img_data->bits_per_pixel, &all->img_data->line_length,
													&all->img_data->endian);
	ft_load_cub(all);
	mlx_put_image_to_window(all->mlx_win->mlx, all->mlx_win->win,
													all->img_data->img, 0, 0);
	write_pix(all, fd);
	mlx_destroy_image(all->mlx_win->mlx, all->img_data->img);
}

void		drow_map(t_all *all)
{
	all->mlx_win->win_x = all->conf_x;
	all->mlx_win->win_y = all->conf_y;
	if (all->conf_x > 8000)
		all->mlx_win->win_x = 8000;
	else if (all->conf_x < 320)
		all->mlx_win->win_x = 320;
	else
		all->mlx_win->win_x = all->conf_x;
	if (all->conf_y > 8000)
		all->mlx_win->win_y = 8000;
	else if (all->conf_y < 240)
		all->mlx_win->win_y = 240;
	else
		all->mlx_win->win_y = all->conf_y;
	put_map(all);
}

int			save_bmp(t_all *all)
{
	char	buf[14];
	char	buffer[40];
	int		fd;
	int		size;

	drow_map(all);
	size = all->mlx_win->win_x * all->mlx_win->win_y * 4 + 54;
	nul_buf(buf, buffer);
	fd = open("screen_cub3D.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (fd < 0)
	{
		printf("Error\nProblem width make screen\n");
		exit_all(all, 1);
	}
	buf[0] = 'B';
	buf[1] = 'M';
	int_to_char(size, buf + 2);
	buf[10] = '6';
	write(fd, buf, 14);
	set_buffer(all, buffer, fd);
	image(all, fd);
	close(fd);
	exit_all(all, 1);
	return (0);
}
