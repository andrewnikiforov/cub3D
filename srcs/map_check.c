/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:30:33 by omillan           #+#    #+#             */
/*   Updated: 2021/03/25 11:56:53 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					max_len(char **ar)
{
	int	max;
	int i;

	i = -1;
	max = 0;
	while (ar[++i])
		if (ft_strlen(ar[i]) > max)
			max = ft_strlen(ar[i]);
	return (max);
}

int					count_colomn(char **ar)
{
	int i;

	i = 0;
	while (ar[i])
		i++;
	return (i);
}

int					flood_fill(int x, int y, char n, char **map)
{
	if (x < 0 || y < 0 || x >= max_len(map) || y >= count_colomn(map) ||
										map[y][x] == ' ' || map[y][x] == 0)
	{
		put_error(5);
		exit(1);
		return (-1);
	}
	if (map[y][x] != n && map[y][x] != ' ' && map[y][x] != '1' &&
															map[y][x] != 0)
	{
		map[y][x] = n;
		flood_fill(x, y - 1, n, map);
		flood_fill(x, y + 1, n, map);
		flood_fill(x + 1, y, n, map);
		flood_fill(x - 1, y, n, map);
		flood_fill(x + 1, y + 1, n, map);
		flood_fill(x - 1, y - 1, n, map);
		flood_fill(x - 1, y + 1, n, map);
		flood_fill(x + 1, y - 1, n, map);
	}
	return (0);
}

char				**copy_map(char **map)
{
	char	**m;
	int		i;

	i = -1;
	if (!(m = malloc(sizeof(char *) * (count_colomn(map) + 1))))
		return (0);
	while (map[++i])
		m[i] = ft_strdup(map[i]);
	m[i] = 0;
	return (m);
}
