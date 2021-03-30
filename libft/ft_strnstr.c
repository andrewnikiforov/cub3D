/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:25:55 by omillan           #+#    #+#             */
/*   Updated: 2021/03/13 14:17:41 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		i;
	size_t		j;
	int			k;

	i = -1;
	if (!*to_find)
		return (-1);
	while (++i < len && *(str + i))
	{
		j = 0;
		if (*(str + i + j) == *(to_find + j))
		{
			k = 0;
			while (i + j < len + 1 && *(str + i + j) && *(to_find + j))
			{
				if (*(str + i + j) != *(to_find + j))
					break ;
				j++;
				k++;
			}
			if (k == ft_strlen(to_find))
				return (i);
		}
	}
	return (-1);
}
