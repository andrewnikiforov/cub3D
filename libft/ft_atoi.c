/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:43:14 by omillan           #+#    #+#             */
/*   Updated: 2021/03/30 14:02:24 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long		help(long long res1, int sign1, int k1)
{
	if (res1 == 0)
		return (0);
	if (k1 >= 19)
	{
		if (sign1 == -1)
			res1 = 0;
		else
			res1 = -1;
	}
	return (res1);
}

int						skip_zero(const char *s, int *i)
{
	int k;
	int j;

	j = *i;
	k = 0;
	while (s[k] == '0')
	{
		k++;
		j++;
	}
	return (j);
}

int						i_count(const char *str, int *sign)
{
	int i;

	i = 0;
	while (((*(str + i) > 8 && *(str + i) < 14) || *(str + i) == ' '))
		i++;
	if (*(str + i) == '+')
		return (300);
	if ((*(str + i) == '-') && ft_isdigit(*(str + i + 1)))
	{
		if (*(str + i) == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

long long				ft_atoi(const char *str)
{
	int			i;
	long long	rez;
	int			sign;
	int			k;

	sign = 1;
	rez = 0;
	k = 1;
	i = i_count(str, &sign);
	if (i == 300)
		return (300);
	i = skip_zero(str + i, &i);
	while (ft_isdigit(*(str + i)))
	{
		rez = rez * 10 + (*(str + i++) - '0');
		k++;
	}
	if (rez == 0 && sign == 1)
		return (0);
	return (sign * help(rez, sign, k));
}
