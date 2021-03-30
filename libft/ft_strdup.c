/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:34:03 by omillan           #+#    #+#             */
/*   Updated: 2021/03/05 14:42:30 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*rez;
	size_t	i;
	size_t	j;

	if (!s1)
		return (0);
	j = -1;
	i = ft_strlen(s1);
	if (!(rez = (char *)malloc((i + 1) * sizeof(char))))
		return (0);
	while (++j < i)
		rez[j] = s1[j];
	rez[j] = '\0';
	return (rez);
}
