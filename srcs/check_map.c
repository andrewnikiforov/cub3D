/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:28:15 by omillan           #+#    #+#             */
/*   Updated: 2021/03/30 15:38:34 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					plr_pos(char **map, int x, int y)
{
	if (x - 1 < 0 || x + 1 > max_len(map))
		return (-1);
	if (map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
		return (-1);
	return (0);
}

int					ft_ft_return(char **m, int i)
{
	num_str_free_arr(m, i);
	return (-1);
}

int					ft_flood(char **map, int k, int j)
{
	int		x;
	int		y;
	char	**m;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_strchr("SWNE", map[y][x]))
			{
				k = x;
				j = y;
				if (plr_pos(map, k, j) == -1)
					return (-1);
			}
		}
	}
	m = copy_map(map);
	if (flood_fill(k, j, '+', m) == -1)
		return (ft_ft_return(m, 2));
	num_str_free_arr(m, 2);
	return (0);
}

int					plr_num(t_all *all, char **map)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("SWNE", map[i][j]))
				count++;
			if (map[i][j] == '2')
				all->spr->count++;
		}
	}
	if (count != 1)
		return (-1);
	return (0);
}

char				**check_map(int argc, char **argv, t_all *all)
{
	int		i;
	int		fd;
	char	**map;
	int		k;
	int		j;

	j = 0;
	k = 0;
	if (argc == 1 || argc > 3)
		ft_return(1, all);
	i = ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]));
	if (i == -1 || argv[1][i + 4] != 0)
		ft_return(1, all);
	if (argv[0][6] != 'D')
		ft_return(9, all);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_return(3, all);
	if ((map = get_map(parser(fd, all), all)) == 0)
		ft_return(4, all);
	if (ft_flood(map, k, j) == -1 || another_char(map) == -1)
	{
		num_str_free_arr(map, 2);
		ft_return(5, all);
	}
	return (map);
}
