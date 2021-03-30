/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_sec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 21:46:48 by omillan           #+#    #+#             */
/*   Updated: 2021/03/30 14:23:36 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					if_no_digit(char **ar)
{
	int		i;
	int		j;

	i = -1;
	while (ar[++i])
	{
		j = -1;
		while (ar[i][++j])
		{
			if (ar[i][j] != ' ' && ar[i][j] != '-' && ar[i][j] != '+'
											&& ft_isdigit(ar[i][j]) == 0)
				return (1);
		}
	}
	return (0);
}

int					count_zpt(char *l)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (l[++i])
	{
		if (l[i] == ',')
			count++;
	}
	return (count);
}

int					count_dig(char *l)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (l[++i])
		if (ft_isdigit(l[i]))
			count++;
	return (count);
}

int					count_alph(char *l)
{
	int i;
	int count;
	int space;

	space = 0;
	i = 0;
	count = 0;
	while (l[i])
	{
		if ((l[i] < '0' || l[i] > '9') && l[i] != ' ')
			count++;
		if (l[i] == ' ')
			space++;
		i++;
	}
	if (space == ft_strlen(l))
		count++;
	return (count);
}

int					is_minus(char *s)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (s[++i])
		if (s[i] == '-')
			count++;
	return (count);
}
