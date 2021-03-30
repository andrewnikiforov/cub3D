/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:18:40 by omillan           #+#    #+#             */
/*   Updated: 2021/03/06 19:44:56 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2)
{
	if (*(int *)s1 > *(int *)s2)
		return (1);
	if (*(int *)s1 < *(int *)s2)
		return (-1);
	if (*(int *)s1 == *(int *)s2)
		return (0);
	return (0);
}
