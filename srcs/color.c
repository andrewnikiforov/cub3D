/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:28:22 by omillan           #+#    #+#             */
/*   Updated: 2021/03/25 12:27:45 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	nul_buf(char *buf, char *buffer)
{
	int i;

	i = 0;
	while (i < 14)
		buf[i++] = (unsigned char)(0);
	i = 0;
	while (i < 40)
		buffer[i++] = (unsigned char)(0);
}

int		another_char(char **map)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (ft_strchr("NEWS102 ", map[i][j]) == 0)
				return (-1);
	}
	return (0);
}
