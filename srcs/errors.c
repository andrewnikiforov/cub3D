/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:29:57 by omillan           #+#    #+#             */
/*   Updated: 2021/03/30 15:38:44 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			put_error(int i)
{
	if (i == 1)
		printf("\033[31m""Error\nNumber of arguments mismatch!\n");
	if (i == 2)
		printf("\033[31m""Error\nInvalid map extension!\n");
	if (i == 3)
		printf("\033[31m""Error\nThe file does not exist!\n");
	if (i == 4)
		printf("\033[31m""Error\nWrong parametr!\n");
	if (i == 5)
		printf("\033[31m""Error\nWrong map!\n");
	if (i == 6)
		printf("\033[31m""Error\nThe problem with the player!\n");
	if (i == 7)
		printf("\033[31m""Error\nWrong argument --save!\n");
	if (i == 8)
		printf("\033[31m""Error\nWrong texture file!\n");
	if (i == 9)
		printf("\033[31m""Error\nWrong programm name!\n");
}

int				check_file(char *s)
{
	int		fd;
	char	*buf;

	if (!(buf = malloc(10)))
		return (-1);
	if ((fd = open(s, O_RDONLY)) < 0)
	{
		free(buf);
		close(fd);
		return (-1);
	}
	if (read(fd, buf, 10) == 0)
	{
		free(buf);
		close(fd);
		return (-1);
	}
	free(buf);
	close(fd);
	return (0);
}

int				trim(char *s, t_all *all)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (i == ft_strlen(s) && all->f->m == 0 && i > 0)
	{
		free(s);
		put_error(4);
		exit_all(all, 0);
	}
	if (i == ft_strlen(s) && all->f->m == 0 && i == 0)
	{
		free(s);
		return (-1);
	}
	return (i);
}

void			if_e(t_all *all)
{
	all->plr->dir_x = 1;
	all->plr->dir_y = 0;
	all->plr->plan_x = 0;
	all->plr->plan_y = 0.66;
}

void			ft_return(int i, t_all *all)
{
	put_error(i);
	exit_all(all, 0);
}
